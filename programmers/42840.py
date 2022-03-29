"""
https://programmers.co.kr/learn/courses/30/lessons/42840
완전탐색 > 모의고사

- 제한조건
시험은 최대 10,000 문제로 구성되어있습니다.
문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.

- 입출력예
answers		return
[1,2,3,4,5]	[1]
[1,3,2,4,2]	[1,2,3]
"""

""" 맞은 내풀이 """
import copy

def solution(answers):
    a1 = copy.deepcopy(answers)
    a2 = copy.deepcopy(answers)
    a3 = copy.deepcopy(answers)
    answer = []
    cnt1 = cnt2 = cnt3 = 0
    one = [1,2,3,4,5]
    two = [2,1,2,3,2,4,2,5]
    thr = [3,3,1,1,2,2,4,4,5,5]
    
    while len(a1) != 0:
        for i in zip(one, a1):
            if i[0] == i[1]:
                cnt1 += 1
        if len(a1) > len(one):
            del a1[0:len(one)]
        else:
            del a1[0:len(a1)]
    answer.append(cnt1)
    
    while len(a2) != 0:
        for j in zip(two, a2):
            if j[0] == j[1]:
                cnt2 += 1
        if len(a2) > len(two):
            del a2[0:len(two)]
        else:
            del a2[0:len(a2)]        
    answer.append(cnt2)
    
    while len(a3) != 0:
        for k in zip(thr, a3):
            if k[0] == k[1]:
                cnt3 += 1
        if len(a3) > len(thr):
            del a3[0:len(thr)]
        else:
            del a3[0:len(a3)]
    answer.append(cnt3)
    
    ans = []
    max_num = max(answer)
    for i in range(len(answer)):
        if answer[i] == max_num:
            ans.append(i+1)
    return ans


"""
맞은 다른사람풀이
성능 더 좋음
"""

def solution(answers):
    pattern1 = [1,2,3,4,5]
    pattern2 = [2,1,2,3,2,4,2,5]
    pattern3 = [3,3,1,1,2,2,4,4,5,5]
    score = [0, 0, 0]
    result = []

    for idx, answer in enumerate(answers):
        if answer == pattern1[idx%len(pattern1)]:
            score[0] += 1
        if answer == pattern2[idx%len(pattern2)]:
            score[1] += 1
        if answer == pattern3[idx%len(pattern3)]:
            score[2] += 1

    for idx, s in enumerate(score):
        if s == max(score):
            result.append(idx+1)

    return result
