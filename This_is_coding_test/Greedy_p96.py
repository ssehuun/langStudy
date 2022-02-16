# 숫자 카드 게임

N, M = map(int, input().split())
li = []

result = 0
for _ in range(N):
    in_li = list(map(int, input().split()))
    if min(in_li) > result:
        result = min(in_li)

print(result)
