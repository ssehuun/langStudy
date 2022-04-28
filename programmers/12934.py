"""
https://programmers.co.kr/learn/courses/30/lessons/12934
연습문제 > 정수 제곱근 판별

- 제한사항
n은 1이상, 50000000000000 이하인 양의 정수입니다.

-입출력예
n		return
121		144
3		-1
"""

""" 맞은 내풀이"""
from math import sqrt

def solution(n):
    if sqrt(n).is_integer() == True:
        return (sqrt(n)+1) ** 2
    else:
        return -1


""" 다른 사람풀이"""
def nextSqure(n):
    sqrt = n ** (1/2)
    if sqrt % 1 == 0:
        return (sqrt + 1) ** 2
    return -1
