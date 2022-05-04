"""
https://programmers.co.kr/learn/courses/30/lessons/12933
연습문제> 정수 내림차순으로 배치하기

- 제한조건
n은 1이상 8000000000 이하인 자연수입니다.

- 입출력예
n		return
118372	873211
"""

""" 내 맞은 풀이 """
# int 변환은 생략해도 되었음

def solution(n):
    s = str(n)
    li = [int(i) for i in s]
    s_li = sorted(li, reverse=True)
    st_li = [str(j) for j in s_li]
    ans = ''.join(st_li)
    return int(ans)


""" 간단한 풀이 """
def solution(n):
    li = list(str(n))    
    s_li = sorted(li, reverse=True)    
    return int(''.join(s_li))
