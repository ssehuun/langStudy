"""
https://programmers.co.kr/learn/courses/30/lessons/42889
2019 KAKAO BLIND RECRUITMENT > 실패율

- 제한사항
스테이지의 개수 N은 1 이상 500 이하의 자연수이다.
stages의 길이는 1 이상 200,000 이하이다.
stages에는 1 이상 N + 1 이하의 자연수가 담겨있다.
각 자연수는 사용자가 현재 도전 중인 스테이지의 번호를 나타낸다.
단, N + 1 은 마지막 스테이지(N 번째 스테이지) 까지 클리어 한 사용자를 나타낸다.
만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 하면 된다.
스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다.

- 입출력예
N	stages						result
5	[2, 1, 2, 6, 2, 4, 3, 3]	[3,4,2,1,5]
4	[4,4,4,4,4]					[4,1,2,3]
"""


""" 런타임 에러 내풀이 """ 
def solution(N, stages):
    dic = {}
    for s in range(1, N+1):
        not_clear = 0
        reach_player = 0
        for i in stages:
            if s == i:
                not_clear += 1
            elif s < i:
                reach_player += 1
        dic[s] = not_clear/(reach_player+not_clear)
    return sorted(dic, key = lambda x:dic[x], reverse=True) 


""" 맞은 다른사람 풀이"""
def solution(N, stages):
    result = {}
    deno = len(stages)
    for s in range(1, N+1):
        if deno != 0:
            cnt = stages.count(s)
            result[s] = cnt / deno
            deno -= cnt
        else:
            result[s] = 0
    return sorted(result, key=lambda x: result[x], reverse=True)
