"""
https://programmers.co.kr/learn/courses/30/lessons/12947
연습문제 > 하샤드 수

- 제한조건
x는 1 이상, 10000 이하인 정수입니다.

- 입출력예
arr		return
10		true
12		true
11		false
13		false
"""


""" 맞은 나의 풀이"""
def solution(x):
    s = str(x)
    li = [int(i) for i in s]
    if x % sum(li) == 0:
        return True
    else:
        return False


""" 간단한 다른 사람 풀이"""
def Harshad(n):
    # n은 하샤드 수 인가요?
    return n % sum([int(c) for c in str(n)]) == 0
