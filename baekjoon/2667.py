# 단지번호붙이기 - https://www.acmicpc.net/problem/2667

from collections import deque

n = int(input())
g = []
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

for _ in range(n):
    l = list(map(int, input()))
    g.append(l)

def bfs(y, x):
    q = deque()
    q.append((y, x))
    g[y][x] = 0
    num = 1
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if ny >= n or ny < 0 or nx >= n or nx < 0: continue
            if g[ny][nx] == 0: continue
            if g[ny][nx] == 1:
                q.append((ny, nx))
                g[ny][nx] = 0
                num += 1
    return num

li_num = []
for i in range(n):
    for j in range(n):
        if g[i][j] == 0: continue
        else:
            li_num.append(bfs(i, j))
            li_num.sort()

print(len(li_num))
for i in li_num:
    print(i)
