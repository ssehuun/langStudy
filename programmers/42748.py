"""
https://programmers.co.kr/learn/courses/30/lessons/42748
정렬 > K번째수

- 제한사항
array의 길이는 1 이상 100 이하입니다.
array의 각 원소는 1 이상 100 이하입니다.
commands의 길이는 1 이상 50 이하입니다.
commands의 각 원소는 길이가 3입니다.

- 입출력예
array					commands							result
[1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]	[5, 6, 3]
"""

""" 나의 풀이 """
def solution(array, commands):
    answer = []
    for c in commands:
        s_li = sorted(array[c[0]-1:c[1]])
        answer.append(s_li[c[2]-1])
    return answer


""" 맞은 다른사람 풀이 """
def solution(array, commands):
    return list(map(lambda x:sorted(array[x[0]-1:x[1]])[x[2]-1], commands))
