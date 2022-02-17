"""
https://programmers.co.kr/learn/courses/30/lessons/92334
2022 KAKAO BLIND RECRUITMENT > 신고 결과 받기

2 ≤ id_list의 길이 ≤ 1,000
1 ≤ id_list의 원소 길이 ≤ 10
1 ≤ report의 길이 ≤ 200,000
3 ≤ report의 원소 길이 ≤ 21

입력1
id_list - ["muzi", "frodo", "apeach", "neo"]
report - ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
k - 2

출력1
result - [2,1,1,0]

입력2
id_list - ["con", "ryan"]
report - ["ryan con", "ryan con", "ryan con", "ryan con"]
k - 3

출력2
result - [0,0]
"""
""" 성공 풀이 """
def solution(id_list, report, k):
    report_set = set(report) # report에서 중복신고한걸 set으로 변환
    caller_dict = {string:0 for string in id_list} # 신고한 카운트
    id_dict = {string:0 for string in id_list} #신고받은 카운트

    for user in report_set:
        if user.split()[1] in id_dict:
            id_dict[user.split()[1]] += 1

    real_li = [] # k번이상 신고당한 사람 리스트
    for man, cnt in id_dict.items():
        if cnt >= k: # k만큼 신고받은 사람 체크 b d
            real_li.append(man)

    for r in report_set:
        if r.split()[1] in real_li:
            caller_dict[r.split()[0]] += 1

    return list(caller_dict.values())

"""
실패 풀이
윈인 : 이중 for문으로 200,000 * 1000 번으로 시간초과 발생
"""
def solution(id_list, report, k):
    report_set = set(report) # report에서 중복신고한걸 set으로 변환
    # print(report_set)
    caller_dict = {string:0 for string in id_list} # 신고한 카운트
    id_dict = {string:0 for string in id_list} # 신고받은 카운트

    for user in report_set:
        if user.split()[1] in id_dict:
            id_dict[user.split()[1]] += 1
            # print(id_dict)
    for man, cnt in id_dict.items():
        if cnt >= k: # k만큼 신고받은 사람 체크 b d
            for c in report_set:
                if man == c.split()[1]:
                    caller_dict[c.split()[0]] += 1


    return list(caller_dict.values())
