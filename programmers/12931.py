"""
https://programmers.co.kr/learn/courses/30/lessons/12931
연습문제 > 자릿수 더하기

- 제한사항
N의 범위 : 100,000,000 이하의 자연수

- 입출력예
N		answer
123		6
987		24
"""


""" 맞은 내풀이"""
def solution(n):
    return sum(map(int, list(str(n))))


# 재귀함수를 통한 풀이법
""" 다른 사람풀이"""
def sum_digit(number):
    if number < 10:
        return number;
    return (number % 10) + sum_digit(number // 10)
