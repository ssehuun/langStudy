"""
Input:
5
8 3 7 9 2
3
5 7 9
Output: no yes yes
"""

n = int(input())
set_arr = set(map(int, input().split()))

m = int(input())
target_arr = list(map(int, input().split()))

for j in target_arr:
    if j in set_arr:
        print('yes', end=' ')
    else:
        print('no', end=' ')
