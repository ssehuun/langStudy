# 그리디 - 큰 수의 법치(p92)
# M의 조건이 10000이하 일때 가능한 나의 풀이법
N, M, K = map(int, input().split())

li = list(map(int, input().split()))
cnt = 0
li.sort(reverse=True)

while M > 0:
    K = 3
    for _ in range(K):
        cnt += li[0]
        M -= 1
        cnt += li[1]
        M -= 1

print(cnt)
