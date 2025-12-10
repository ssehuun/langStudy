# Input1: 10 7
# Input2: 1 3 5 7 9 11 13 15 17 19
# Output: 4

# Input1: 10 7
# Input2: 1 3 5 6 9 11 13 15 17 19
# Output: 4

def binary_search_recursion(array, target, start, end):
    if start > end:
        return None
    mid = (start + end) // 2

    if array[mid] == target:
        return mid
    elif array[mid] > target:
        return binary_search_recursion(array, target, start, mid-1)
    else:
        return binary_search_recursion(array, target, mid+1, end)

n, target = list(map(int, input().split()))

array = list(map(int, input().split()))

result = binary_search_recursion(array, target, 0, n-1)
if result == None:
    print("target 원소가 존재하지 않습니다")
else:
    print(f"{result+1}번째 원소에 존재합니다")
