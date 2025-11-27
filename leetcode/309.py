# 309. Best Time to Buy and Sell Stock with Cooldown 
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
# https://kayath.tistory.com/42

# Input1: prices = [1,2,3,0,2]
# Output:1 3

# Input2: prices = [1]
# Output2: 0

# Input3: [48,12,60,93,97,42,25,64,17,56,85,93,9,48,52,42,58,85,81,84,69,36,1,54,23,15,72,15,11,94]
# Output3: 428


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [[0 for _ in range(2)] for _ in range(n + 2)]

        for i in range(n - 1, -1, -1):
            # When we can buy
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1])

            # When we can sell
            dp[i][0] = max(prices[i] + dp[i + 2][1], dp[i + 1][0])

        return dp[0][1]
