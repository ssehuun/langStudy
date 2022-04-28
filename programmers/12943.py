"""
https://programmers.co.kr/learn/courses/30/lessons/12943
연습문제 > 콜라츠 추측

- 제한사항
입력된 수, num은 1 이상 8000000 미만인 정수입니다.

- 입출력예
n		result
6		8
16		4
626331	-1
"""

""" 맞은 내풀이 """
def solution(num):
    cnt = 0
    while num != 1:
        if num % 2 == 0:
            num = num // 2
        else:
            num = num * 3 + 1
        cnt = cnt + 1
        if cnt >= 500:
            return -1
    return cnt


""" pythonic한 다른사람 풀이 """
def collatz(num):
    for i in range(500):
        num = num / 2 if num % 2 == 0 else num*3 + 1
        if num == 1:
            return i + 1
    return -1
