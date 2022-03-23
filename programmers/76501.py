"""
https://programmers.co.kr/learn/courses/30/lessons/76501
월간 코드 챌린지 시즌2 > 음양 더하기

- 제한사항
absolutes의 길이는 1 이상 1,000 이하입니다.
absolutes의 모든 수는 각각 1 이상 1,000 이하입니다.
signs의 길이는 absolutes의 길이와 같습니다.
signs[i] 가 참이면 absolutes[i] 의 실제 정수가 양수임을, 그렇지 않으면 음수임을 의미합니다.

- 입출력예
absolutes	signs				result
[4,7,12]	[true,false,true]	9
[1,2,3]		[false,false,true]	0
"""

"""맞은 내 풀이"""
def solution(absolutes, signs):
    for s in range(len(signs)):
        if signs[s] == False:
            absolutes[s] = -absolutes[s]
    
    return sum(absolutes)


"""zip 을 활용한 풀이"""
def solution(absolutes, signs):
    return sum(a if s else -a for a, s in zip(absolutes, signs))
