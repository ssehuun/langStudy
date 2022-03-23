"""
https://programmers.co.kr/learn/courses/30/lessons/70128
월간 코드 챌린지 시즌1 > 내적

- 제한사항
a, b의 길이는 1 이상 1,000 이하입니다.
a, b의 모든 수는 -1,000 이상 1,000 이하입니다.

- 입출력 예
a			b			result
[1,2,3,4]	[-3,-1,0,2]	3
[-1,0,1]	[1,0,-1]	-2

"""

""" 성공 내풀이 """
def solution(a, b):
    return sum(f * r for f, r in zip(a, b))
