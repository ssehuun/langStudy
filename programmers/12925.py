"""
https://programmers.co.kr/learn/courses/30/lessons/12925
연습문제 > 문자열을 정수로 바꾸기

- 제한조건
s의 길이는 1 이상 5이하입니다.
s의 맨앞에는 부호(+, -)가 올 수 있습니다.
s는 부호와 숫자로만 이루어져있습니다.
s는 "0"으로 시작하지 않습니다.

- 입출력예
예를들어 str이 "1234"이면 1234를 반환하고, "-1234"이면 -1234를 반환하면 됩니다.
str은 부호(+,-)와 숫자로만 구성되어 있고, 잘못된 값이 입력되는 경우는 없습니다.
"""

""" 맞은 내풀이"""
def solution(s):
    if s[0] == "-":
        li = int(s[1:])
        num = -li        
    else:
        num = int(s)        
    return num


# 파이썬은 부호 문자열도 int()로 변환가능하다
""" 다른 사람풀이"""
def strToInt(str):
    return int(str)
