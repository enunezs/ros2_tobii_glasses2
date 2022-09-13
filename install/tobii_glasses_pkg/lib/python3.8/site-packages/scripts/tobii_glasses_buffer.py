import json


# Change to queue?

class TobiiGlassesBuffer:

    def __init__(self):
        self.offset_buffer = {}
        self.sensor_data_buffer = {}
        self.last_pts = 0
        self.pts_video_to_glasses_offset = 0
        self.pts_offset = None

    # TODO: use latency property
    def get_synced_data(self, json_data, video_pts, debug = False): 

        # * General process:
        # * [video pts] -> [offset pts, sensor ts] -> [sensor ts, data]

        # Also calculates the video timestamp to message timestamp offset
        def add_data_to_buffers(self, json_data):
            # If the data has a pts and its valid, add ts to the offset buffer indexed by the scaled pts
            if "pts" in json_data and json_data['pts']['s']==0:
                conversion_cnst = 0.09 # 90KHz in microseconds (!), unconfirmed
                offset_pts = int(json_data['pts']['pts']/conversion_cnst)

                if not offset_pts in self.offset_buffer:
                    # Code as is sets the offset to the latest message,
                    # I believe it is correct but it might not be the fully intended behaviour.
                    offset_ts = json_data['pts']['ts']
                    self.offset_buffer[offset_pts] = offset_ts #-json_data["gp"]['l']
                    
            # TODO: Change to sub json for scalability
            if "gp" in json_data and json_data['gp']['s']==0:
                
                #Latency means data should be earlier relative to the timestamp 
                # TODO (test) with dummy var
                #latency = 10000000
                
                #latency = 0
                latency = json_data["gp"]['l']

                sensor_ts = json_data['gp']['ts'] + latency 
                self.sensor_data_buffer[sensor_ts] = json_data.copy()

        def get_cur_pts(self, video_pts):

            # First time only
            if not self.pts_offset:
                self.pts_offset = min(self.offset_buffer.keys())-video_pts
            # Simply the initial pts + the video pts
            #Basic method
            cur_pts = video_pts + self.pts_offset
            #self.pts_video_to_sensor_offset = offset_pts-video_pts #1000000

            # TODO: Apply delta when buffer changes and flush?
            """
            if not self.first_pts:
                self.first_pts = offset_pts-video_pts
            """

            return cur_pts

        # Gets ts latest from the latest pts
        def get_cur_ts(self, cur_pts):
            # get closes pts in the offset_buffer: largest that is smaller than the timestamp
            prev_pts = min(self.offset_buffer.keys())


            for pts in self.offset_buffer: #iterate over key
                if pts <= cur_pts and pts>prev_pts: # TODO: Rewrite in gamma notation(?)
                    prev_pts = pts

            # apply offset and get associated ts
            cur_ts = self.offset_buffer[prev_pts] + (cur_pts - prev_pts) 
            return cur_ts

        # TODO: Expand to other data types
        def get_buffered_data(self, cur_ts):
            #print("Looking for buffered data")
            # get closes ts in the sensor_data_buffer: largest that is smaller than the timestamp
            cur_data_ts = min(self.sensor_data_buffer.keys())
            #print(f"default prev pts {cur_data_ts}")

            #print(f"First element {cur_data_ts}")
            #print(f"Limit is current timestamp: {cur_ts}")

            for ts in self.sensor_data_buffer:
                if ts <= cur_ts and ts>cur_data_ts:
                    cur_data_ts = ts

            cur_data = self.sensor_data_buffer[cur_data_ts]
            #print(f"Associated data {cur_data}")

            return cur_data

        def flush_buffer(buffer, timestamp):
            # Get keys smaller than the timestamp
            #get before and after dict

            # TODO: if buffer size 0 or 1 return
            #print(f"Buffer before: {buffer}")
            #print(f"Filter timestamp: {timestamp} ")

            if len(buffer) <=1:
                return buffer

            prev_ts = { k: v for k,v in buffer.items() if k <= timestamp }
            next_ts = { k: v for k,v in buffer.items() if k > timestamp }


            #print(f"Next: {next_ts}")
            updated_buffer = next_ts   
            # Insert the last element of the previous dict into the next dict
            if prev_ts:
                last_ts = max(list(prev_ts.keys()))
                updated_buffer[last_ts] = prev_ts[last_ts]
                #print(f"Final: {last_ts}")

            #print(f"Prev: {prev_ts}")
            #print(f"Buffer after: {updated_buffer}")

            return updated_buffer

        # Add new data to respective data_stream:
        # sync_buffer contains the pts-ts pairs
        # sensor_buffer contains the ts-data for each sensor list
        add_data_to_buffers(self, json_data)

        # With the video pts get the current (sensor) pts 
        current_pts = get_cur_pts(self, video_pts)
        # and find the current_pts (inmediate previous) ts in the sensor buffer
        current_ts = get_cur_ts(self, current_pts)

        # Get new data from json_data, pull closest ts from sensor buffer
        cur_data = get_buffered_data(self, current_ts)

        if debug:
            print(f"Video pts: {video_pts/1000:,}")
            print(f"Current adjusted pts: {current_pts/1000000:,}")
            
            print(f"Offset buffer: {self.offset_buffer}")
            print(f"current ts is {current_ts/1000000:,}")

            print(f"Sensor buffer timestamps: {self.sensor_data_buffer}")
            print(f"current gp is {cur_data}")

            print(f"Video pts - data offset: {(current_ts-current_pts)/1000000:,} micro seconds")
            print(f"----")

        # Discard unneeded buffer data
        self.offset_buffer = flush_buffer( self.offset_buffer, current_pts)
        self.sensor_data_buffer = flush_buffer( self.sensor_data_buffer, current_ts)

        return cur_data


