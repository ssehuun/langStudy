"""
이진탐색 - 계수정렬
Input:
5
8 3 7 9 2
3
5 7 9
Output: no yes yes
"""

n = int(input())
arr = [0] * 1000001

for i in input().split():
    arr[int(i)] = 1

m = int(input())
target_arr = list(map(int, input().split()))

for j in target_arr:
    if arr[j] == 1:
        print('yes', end=' ')
    else:
        print('no', end=' ')
