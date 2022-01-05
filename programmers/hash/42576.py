"""
완주하지 못한 선수
sub_task - 100
effiecincy - 100
dictionary, get(key, default_value) - if not key return default_value
"""

def solution(participant, completion):
    answer = {}
    for i in participant:
        answer[i] = answer.get(i, 0)+1
    for j in completion:
        answer[j] = answer[j]-1
    for k in answer:
        if answer[k]: return k
