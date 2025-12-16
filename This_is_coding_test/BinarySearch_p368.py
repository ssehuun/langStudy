"""
Input1: 5
-15 -6 1 3 7
Output: 3

Input2: 7
-15 -4 2 8 9 13 15
Output: 2

Input3: 7
-15 -4 3 8 9 13 15
Output: -1
"""

import sys

n = int(input())
arr = list(map(int, sys.stdin.readline().split()))
# arr = list(map(int, input().split()))

def binary_search(array, start, end):
    while start <= end:
        mid = (start + end) // 2
        if array[mid] == mid:
            return mid
        elif array[mid] > mid:
            end = mid -1
        else:
            start = mid + 1
    return None

result = binary_search(arr, 0, len(arr)-1)
if result is not None:
    print(result)
else:
    print(-1)
