#User function Template for python3

class Solution:
    def countStrings(self, n, k): 
        # code here # Python3 program to count number of
# binary strings with k times appearing
# consecutive 1's.

    
        # dp[i][j][0] stores count of binary
        # strings of length i with j consecutive
        # 1's and ending at 0.
        # dp[i][j][1] stores count of binary
        # strings of length i with j consecutive
        # 1's and ending at 1.
        dp = [[[0, 0] for __ in range(k + 1)]
                      for _ in range(n + 1)]
     
        # If n = 1 and k = 0.
        dp[1][0][0] = 1
        dp[1][0][1] = 1
     
        for i in range(2, n + 1):
             
            # number of adjacent 1's can not exceed i-1
            for j in range(k + 1):
                dp[i][j][0] = (dp[i - 1][j][0] +
                               dp[i - 1][j][1])
                dp[i][j][1] = dp[i - 1][j][0]
                if j >= 1:
                    dp[i][j][1] += dp[i - 1][j - 1][1]
     
        return (dp[n][k][0] + dp[n][k][1]) % (10**9 + 7)




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        n,k = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.countStrings(n,k))
# } Driver Code Ends