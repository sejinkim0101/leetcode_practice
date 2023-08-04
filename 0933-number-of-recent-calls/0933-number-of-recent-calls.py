

# SOL1) GPT4. - with collections // Leetcode discussion 과 동일 

# https://leetcode.com/problems/number-of-recent-calls/discuss/3568692/Beating-99.34-Python-Easiest-Solution


from collections import deque

class RecentCounter:
    def __init__(self):
        # self.requests = deque() # Initialize a double-ended queue to store the requests
        self.requests = []
        
    
    def ping(self, t: int) -> int:
        self.requests.append(t) # Add the new request time t to the queue
        
        # Remove requests that are older than 3000 milliseconds from the current time t
        while self.requests and self.requests[0] < t - 3000:
            ## deque를 안 쓰고 pop(0)를 대신 써서도 가능!
            # self.requests.popleft()
            self.requests.pop(0)
        
        # Return the number of recent requests within the last 3000 milliseconds
        return len(self.requests)

    
## Sol2) GPT4 - without collections 

# class RecentCounter:
#     def __init__(self):
#         self.requests = [] # Initialize an empty list to store the requests
    
#     def ping(self, t: int) -> int:
#         self.requests.append(t) # Add the new request time t to the list
        
#         # Remove requests that are older than 3000 milliseconds from the current time t
#         # By keeping only those elements in the list that are in the range [t - 3000, t]
#         self.requests = [request for request in self.requests if request >= t - 3000]
        
#         # Return the number of recent requests within the last 3000 milliseconds
#         return len(self.requests)



# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
