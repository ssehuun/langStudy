### 퀵 정렬 0~9 랜덤 수 정렬### 

arr = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]

def quick_sort(arr, start, end):
	if start >= end: #원소가 1개인경우 종료
		return
	pivot = start # 피벗은 첫번째 원소
    left = start + 1
	right = end

	while left <= right:
		# 피벗보다 큰 데이터를 찾을때까지 반복
		while left <= end and arr[left] <= arr[pivot]:
			left += 1
		# 피벗보다 작은 데이터를 찾을때까지 반복
		while right > start and arr[right] >= arr[pivot]:
			right -= 1
		if left > right: # 엇갈렸다면 작은 데이터와 피벗을 교제
			arr[right], arr[pivot] = arr[pivot], arr[right]
		else: # 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
			arr[left], arr[right] = arr[right], arr[left]
	#분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
	quick_sort(arr, start, right-1)
	quick_sort(arr, left+1, end)

quick_sort(arr, 0, len(arr)-1)
print(arr)
