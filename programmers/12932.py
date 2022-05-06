"""
https://programmers.co.kr/learn/courses/30/lessons/12932
연습문제 > 자연수 뒤집어 배열로 만들기

- 제한조건
n은 10,000,000,000이하인 자연수입니다.

- 입출력예
n		return
12345	[5,4,3,2,1]
"""


""" 맞은 내 풀이"""
def solution(n):
    li = [int(i) for i in str(n)]
    li.reverse()
    return li


""" 다른 사람풀이"""
def digit_reverse(n):
    return list(map(int, reversed(str(n))))


def digit_reverse(n):
    return [int(i) for i in str(n)][::-1]
