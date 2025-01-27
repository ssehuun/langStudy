# 1422. Maximum Score After Splitting a String
# https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/


class Solution:
    def maxScore(self, s: str) -> int:
        max_cnt = 0
        for i in range(len(s)):
            if i+1 == len(s): break
            zero_cnt = s[0:i+1].count('0')
            one_cnt = s[i+1:].count('1')
            if max_cnt < (zero_cnt + one_cnt):
                max_cnt = zero_cnt + one_cnt
        return max_cnt
