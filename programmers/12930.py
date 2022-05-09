"""
https://programmers.co.kr/learn/courses/30/lessons/12930
연습문제 > 이상한 문자 만들기

- 제한사항
문자열 전체의 짝/홀수 인덱스가 아니라, 단어(공백을 기준)별로 짝/홀수 인덱스를 판단해야합니다.
첫 번째 글자는 0번째 인덱스로 보아 짝수번째 알파벳으로 처리해야 합니다.

- 입출력예
s					return
"try hello world"	"TrY HeLlO WoRlD"
"""

""" 맞은 내풀이"""
def solution(n):
    li = n.split(" ") #[what the fuck]
    total_st = ""
    for i in li:
        new_st = ""
        for j in range(len(i)):
            if j % 2 == 0:
                new_st += i[j].upper()
            else:
                new_st += i[j].lower()
        total_st += (new_st + " ")
    return total_st[0:-1]


""" 다른 사람풀이"""
def solution(n):
    li = n.split(" ")

    for i in range(len(li)):
        s_li = list(li[i])
        for j in range(len(s_li)):
            if j % 2 == 0:
                s_li[j] = s_li[j].upper()
            else:
                s_li[j] = s_li[j].lower()
        li[i] = "".join(s_li)        
    answer = " ".join(li)
    return answer
