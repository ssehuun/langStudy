"""
https://programmers.co.kr/learn/courses/30/lessons/12944
연습문제 > 평균 구하기

- 제한사항
arr은 길이 1 이상, 100 이하인 배열입니다.
arr의 원소는 -10,000 이상 10,000 이하인 정수입니다.

- 입출력예
arr			return
[1,2,3,4]	2.5
[5,5]		5
"""

"""내가 맞은 풀이"""
def solution(arr):
    return sum(arr)/len(arr)
