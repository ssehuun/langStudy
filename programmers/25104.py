"""
https://programmers.co.kr/learn/courses/30/lessons/42888
2019 KAKAO BLIND RECRUITMENT > 오픈채팅방

- 제한사항
record는 다음과 같은 문자열이 담긴 배열이며, 길이는 1 이상 100,000 이하이다.

- 다음은 record에 담긴 문자열에 대한 설명이다.
모든 유저는 [유저 아이디]로 구분한다.
[유저 아이디] 사용자가 [닉네임]으로 채팅방에 입장 - "Enter [유저 아이디] [닉네임]" (ex. "Enter uid1234 Muzi")
[유저 아이디] 사용자가 채팅방에서 퇴장 - "Leave [유저 아이디]" (ex. "Leave uid1234")
[유저 아이디] 사용자가 닉네임을 [닉네임]으로 변경 - "Change [유저 아이디] [닉네임]" (ex. "Change uid1234 Muzi")
첫 단어는 Enter, Leave, Change 중 하나이다.
각 단어는 공백으로 구분되어 있으며, 알파벳 대문자, 소문자, 숫자로만 이루어져있다.
유저 아이디와 닉네임은 알파벳 대문자, 소문자를 구별한다.
유저 아이디와 닉네임의 길이는 1 이상 10 이하이다.
채팅방에서 나간 유저가 닉네임을 변경하는 등 잘못 된 입력은 주어지지 않는다.

입출력예
record
["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]

result
["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]
"""

""" 틀린 나의 풀이 """
def solution(record):
    u_dict = dict()
    answer = []
    for user in record:
        if user.split()[0] == "Enter" or user.split()[0] == "Change":
            en_ch = user.split()[0]
            uid = user.split()[1]
            if en_ch == "Enter":
                name = user.split()[2]
                tmp = [name, f'{name}님이 들어왔습니다.']
                u_dict[uid] = tmp
                answer.append({uid:tmp})
                continue
            elif en_ch == "Change":
                name = user.split()[2]
                tmp = [name, f'{name}님이 들어왔습니다.']
                u_dict[uid] = tmp
                continue
            elif user.split()[0] == "Leave":
                uid = user.split()[1]
                name = u_dict[uid][0]
                tmp = [name, f'{name}님이 나갔습니다.']
                answer.append({uid:tmp})

            for key, val in u_dict.items():
                for e in answer:
                    if key in e:
                        e[key][0] = val[0]
                        if e[key][1][-7:-6] == "들":
                            e[key][1] = val[0]+e[key][1][-10:]
                        else:
                            e[key][1] = val[0]+e[key][1][-9:]
            ans = []
            for dic in answer:
                for key, val in dic.items():
                    ans.append(val[1])

            return ans

""" 맞는 풀이 """
def solution(record):
    result = []
    info = {}
    for r in record:
        r = r.split()
        #들어온 경우
        if r[0] == "Enter":
            result.append([r[1], "님이 들어왔습니다."])
            info[r[1]] = r[2]
            #나간경우
        elif r[0] == "Leave":
            result.append([r[1], "님이 나갔습니다."])
            #변경된 경우
        else:
            info[r[1]] = r[2]
    result = list(map(lambda x : info[x[0]]+x[1], result))
    return result
