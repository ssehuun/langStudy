"""
1 <= n <= 1,000,000
1 <= m <= 2,000,000,000

Input:
4 6
19 15 10 17
Output: 15
"""
import sys
n, m = map(int, input().split())

dduk_arr = list(map(int, sys.stdin.readline().split()))

start = 0
end = max(dduk_arr)-1
result = 0

while start <= end:
    total = 0
    mid = (start + end) // 2
    for dduk_height in dduk_arr:
        if mid < dduk_height:
            total += (dduk_height - mid)
    # 떡의 양이 부족한 경우 더 많이 자르기(왼쪽 부분 탐색)
    if total < m:
        end = mid - 1
    # 떡의 양이 충분한 경우 덜 자르기(오른쪽 부분 탐색)
    else:
        result = mid # 최대한 덜 잘랐을때가 정답 
        start = mid + 1    
        
print(result)
