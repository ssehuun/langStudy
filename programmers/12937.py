"""
https://programmers.co.kr/learn/courses/30/lessons/12937
연습문제 > 짝수와 홀수

- 제한조건
num은 int 범위의 정수입니다.
0은 짝수입니다.

- 입출력예
num		return
3		"Odd"
4		"Even"
"""

""" 나의 맞은 풀이 """
def solution(num):
    return "Even" if num % 2 == 0 else "Odd"


# 아래는 비트 연산자를 통해 리스트의 인덱스로 리턴하게 한 방법
""" 맞은 다른사람 풀이 """
def evenOrOdd(num):
    return ["Even", "Odd"][num & 1]

