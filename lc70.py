# Question: When climbing a stair, could go up 1 or 2 steps each time, count the ways to go upstairs.
# F(n) = F(n-1) + F(n-2)
# Wentao Sun, 2024-11-7

class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [1, 1]
        for i in range(2, n+1):
            dp.append(dp[i-1] + dp[i-2])
        return dp[n]