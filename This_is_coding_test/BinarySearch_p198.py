"""
Input:
5
8 3 7 9 2
3
5 7 9
Output: no yes yes
"""
import sys


def binary_search(array, target, start, end):
    sort_arr = sorted(array)
    while start <= end:
        mid = (start + end) // 2
        if sort_arr[mid] == target:
            return mid
        elif sort_arr[mid] > target:
            end = mid-1
        else:
            start = mid+1
    return None

N = int(input())
arr = list(map(int, input().split()))

M = int(input())
chk_arr = list(map(int, input().split()))

for chk_num in chk_arr:
    result = binary_search(arr, chk_num, 0, N-1)
    if result != None:
        print('yes', end=' ')
    else:
        print('no', end=' ')
