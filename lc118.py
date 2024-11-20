class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if n < 1:
            return
        n = numRows
        dp = [ [1] * i for i in range(1, n+1)]
        for r in range(1,n):
            for c in range(1,n-1):
                dp[r][c] = dp[r-1][c-1] + dp[r-1][c]
        return dp