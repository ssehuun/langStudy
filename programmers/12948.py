"""
https://programmers.co.kr/learn/courses/30/lessons/12948
연습문제 > 핸드폰 번호 가리기

- 제한조건
phone_number는 길이 4 이상, 20이하인 문자열입니다.

- 입출력예
phone_number	return
"01033334444"	"*******4444"
"027778888"		"*****8888"

"""

""" 내 맞은 풀이"""
def solution(phone_number):
    answer = ''
    answer = answer.join("*" for s in phone_number[0:len(phone_number)-4])
    tail = ''.join(phone_number[len(phone_number)-4::])
    answer = answer+tail    
    return answer


""" 간단한 다른사람 풀이"""
def hide_numbers(s):
    return "*"*(len(s)-4) + s[-4:]
