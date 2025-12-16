"""
정렬된 배열에서 특정 수의 개수 구하기

Input1
7 2
1 1 2 2 2 2 3
Output1: 4
Input2
7 4
1 1 2 2 2 2 3
Output2: -1
"""
n, x = map(int, input().split())
arr = list(map(int, input().split()))

from bisect import bisect_left, bisect_right

left_loc = bisect_left(arr, x)
right_loc = bisect_right(arr, x)

if right_loc-left_loc:
  print(right_loc-left_loc)
else:
  print(-1)


"""
내가 짠 코드
최악의 시간 복잡도: O(n^2)
최선의 시간 복잡도: O(k*logn)

def binary_search_while(array, target, start, end):
  print(f"array: {array}")
  while start <= end:
    if start > end:
      break
    mid = (start + end) // 2

    if array[mid] == target:
      return mid

    elif array[mid] > target:
      end = mid - 1
    else:
      start = mid + 1
  return None

cnt = 0

while True:
  n_len = len(arr)
  mid = binary_search_while(arr, x, 0, n_len - 1)
  print(f"mid : {mid}, arr : {arr}")
  if mid is not None:
    cnt += 1
    del arr[mid]
    print(f"del arr : {arr}")
  elif mid is None:
    if cnt != 0:
      print(cnt)
      break
    else:
      print(-1)
      break
"""
