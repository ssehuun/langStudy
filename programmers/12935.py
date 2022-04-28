"""
https://programmers.co.kr/learn/courses/30/lessons/12935
연습문제 > 제일 작은 수 제거하기

- 제한조건
arr은 길이 1 이상인 배열입니다.
인덱스 i, j에 대해 i ≠ j이면 arr[i] ≠ arr[j] 입니다.

- 입출력예
arr			return
[4,3,2,1]	[4,3,2]
[10]		[-1]
"""


""" 맞은 내풀이 """
def solution(arr):
    arr.remove(min(arr))
    return arr if len(arr) != 0 else [-1]
