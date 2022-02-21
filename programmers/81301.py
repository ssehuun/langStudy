"""
https://programmers.co.kr/learn/courses/30/lessons/81301
2021 카카오 채용연계형 인턴십 > 숫자 문자열과 영단어

제한사항
1 ≤ s의 길이 ≤ 50
s가 "zero" 또는 "0"으로 시작하는 경우는 주어지지 않습니다.
return 값이 1 이상 2,000,000,000 이하의 정수가 되는 올바른 입력만 s로 주어집니다.

입출력
"one4seveneight" / 1478
"23four5six7" / 234567
"2three45sixseven" / 234567
"123" / 123
"""

""" 성공 풀이 """

num_dic = {"zero": 0, "one":1, "two":2, "three":3, "four":4, "five":5, "six":6, "seven":7, "eight":8, "nine":9}

def solution(s):
    for st_key, num_val in num_dic.items():
        if st_key in s:
            s = s.replace(st_key, str(num_val))
    return int(s)
