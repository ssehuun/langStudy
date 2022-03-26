"""
https://programmers.co.kr/learn/courses/30/lessons/12969
연습문제 > 직사각형 별찍

- 제한조건
n과 m은 각각 1000 이하인 자연수입니다.

- 입력조건
입력 5 3
출력
*****
*****
*****
"""

""" 맞은 내풀이 """
a, b = map(int, input().strip().split(' '))
for _ in range(b):
    print("*" * a)

""" 맞은 다른사람풀이"""
a, b = map(int, input().strip().split(' '))
print(("*" * a + '\n')*b)
