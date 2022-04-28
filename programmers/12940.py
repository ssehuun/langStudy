"""
https://programmers.co.kr/learn/courses/30/lessons/12940
연습문제 > 최대공약수와 최소공배수

- 제한사항
두 수는 1이상 1000000이하의 자연수입니다.

-입출력예
n	m	return
3	12	[3,12]
2	5	[1,10]
"""

""" 맞은 내풀이 """
from math import gcd

def solution(n, m):
    answer = []
    answer.append(gcd(n, m))
    answer.append(n*m // gcd(n, m))
    return answer

# python 3.8버전에서는 최소공배수 함수인 lcd를 사용할 수 없다.
# 유클리드 호제법 풀이도 참고하자


""" 유클리드 호제법 풀이 """
def solution(a, b):
    answer = []
    m, n = max(a, b), min(a, b)
    while n > 0:
        m, n = n, m % n
    answer = [m, a * b // m]
    return answer

