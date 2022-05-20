"""
https://programmers.co.kr/learn/courses/30/lessons/12921
연습문제 > 소수 찾기

- 제한조건
n은 2이상 1000000이하의 자연수입니다.

- 입출력예
n	result
10	4
5	3
"""

""" 맞은 내풀이(에라토스테네스의 채)"""
def solution(n):    
    numli = [True] * (n+1) # 에라토스테네스의 체 초기화: n개 요소에 True 설정(소수로 간주)
    m = int(n ** 0.5) # n의 최대 약수가 sqrt(n) 이하이므로 i=sqrt(n)까지 검사
    for i in range(2, m + 1):
        if numli[i] == True:           # num[i]가 소수인 경우
            for j in range(i+i, n+1, i): # i이후 i의 배수들을 False 판정
                numli[j] = False

    return len([i for i in range(2, n+1) if numli[i] == True])


""" 다른 사람풀이(에라토스테네스의 채 + set활용)"""
def solution(n):
    num=set(range(2,n+1)) #n+1을 제곱근으로 해야 효율성 증대
    for i in range(2,n+1):
        if i in num:
            num-=set(range(2*i,n+1,i))
    return len(num)


""" 내코드와 다른사람풀이의 합체"""
def solution(n):
    num = set(range(2, n+1))
    for i in range(2,int(n**0.5)+1):
        if i in num:
            num -= set(range(i*i,n+1,i)) 
    return len(num)

"""
효율성 테스트에서 내 코드가 더 용량이 작게 나옴
테스트 케이스가 한정적이라 그런걸로 추측..
set은 해시 자료구조라 in 연산자를 쓰면 처음 요소를 찾을때나 마지막 원소를 찾을 때나 비슷한 시간을 가짐
O(1) 시간복잡도임. list는 처음 요소만 빠르고, 나머지는 느림. O(n)시간임
데이터가 크거나 연산이 많을수록, set자료구조를 쓰는게 낫다.
-출처:  https://kyleyj.tistory.com/56
"""
