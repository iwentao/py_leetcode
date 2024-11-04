#!/usr/bin/py
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [-1] * (amount + 1)  
        dp[0] = 0
        for i in range(1, amount+1):
            for j in coins:
                if i >= j and dp[i - j] != -1: # if coin number less than index and has a opticial sub program
                    if dp[i] == -1 or dp[i] > dp[i - j] + 1: # if i not caluclated or it is greater than dp[i-j]+1
                        dp[i] = dp[i- j] + 1
        
        return dp[amount]
