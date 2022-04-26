"""
https://programmers.co.kr/learn/courses/30/lessons/12954
연습문제 > x만큼 간격이 있는 n개의 숫자

- 제한조건
x는 -10000000 이상, 10000000 이하인 정수입니다.
n은 1000 이하인 자연수입니다.

- 입출력 예
x	n	answer
2	5	[2,4,6,8,10]
4	3	[4,8,12]
-4	2	[-4, -8]
"""

""" 맞은 내풀이"""
def solution(x, n):
    answer = []
    tmp = x
    answer.append(x)
    for i in range(1, n):
        tmp += x
        answer.append(tmp)
    return answer


""" 간단한 다른사람 풀이"""
def number_generator(x, n):
    # 함수를 완성하세요
    return [i * x + x for i in range(n)]
