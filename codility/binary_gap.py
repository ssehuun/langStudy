"""
https://app.codility.com/c/run/trainingJXYDGJ-496/

"""


""" 맞은 내 풀이 """₩
def solution(N):
    li = []
    while True:
        if N // 2 >= 2:
            li.append(N % 2)
            N = N // 2
        else:
            li.append(N % 2)
            li.append(N // 2)
            li.reverse()
            break
    max_cnt = 0
    cnt = 0
    leng = 0
    on_off = False
    for i in li:
        leng += 1
        if leng == len(li) and i != 1:
            cnt = 0
            break
        if on_off == False and i == 1:
            on_off = True
        elif on_off == True and i == 0:
            cnt += 1
        elif on_off == True and i == 1:
            if max_cnt < cnt:
                max_cnt = cnt
            cnt = 0
    return max_cnt
