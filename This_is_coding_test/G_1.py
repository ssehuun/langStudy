# 모험가 길드

n = int(input())
l = list(map(int, input().split()))
l.sort()
group = 0
cnt = 0

for i in l:
    cnt += 1
    if cnt >= i:
        group += 1
        cnt = 0
        print(group)
