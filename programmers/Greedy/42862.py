/*
체육복
https://programmers.co.kr/learn/courses/30/lessons/42862
정확성 - 100
<풀이>
아래 조건을 우선적으로 처리하기 위해 set을 사용함

조건 - 여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.

if문의 순서가 중요
(참고 - https://rain-bow.tistory.com/entry/Python-프로그래머스-체육복)
*/
def solution(n, lost, reserve):
    set_r = set(reserve) - set(lost)
    set_l = set(lost) - set(reserve)

    for r in set_r:
        if r-1 in set_l:
            set_l.remove(r-1)
            continue
        elif r+1 in set_l:
            set_l.remove(r+1)
            return n-len(set_l)
