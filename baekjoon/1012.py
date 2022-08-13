# 유기농 배추 - https://www.acmicpc.net/problem/1012

from collections import deque

n = int(input())
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

def bfs(y, x):
    q = deque()
    q.append((y, x))
    g[y][x] = 0
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if ny >= N or ny < 0 or nx >= M or nx < 0: continue
            if g[ny][nx] == 0: continue
            if g[ny][nx] == 1:
                q.append((ny, nx))
                g[ny][nx] = 0

for _ in range(n):
    M, N, K = map(int, input().split())
    cnt = 0
    g = []
    for _ in range(N):
        g.append([0]*M)
    for k in range(K):
        x, y = map(int, input().split())
        g[y][x] = 1
    for i in range(N): # row
        for j in range(M): # column
            if g[i][j] == 0: continue
            else:
                bfs(i, j)
                cnt += 1
    print(cnt)


