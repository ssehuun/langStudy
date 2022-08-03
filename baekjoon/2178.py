#https://www.acmicpc.net/problem/2178

from collections import deque

n, m = map(int, input().split())
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]
g = []
for i in range(n):
    g.append(list(map(int, input())))

def bfs(y, x):
    q = deque()
    q.append((y, x))
    while q:
        sy, sx = q.popleft()
        for i in range(4):
            ry = sy+dy[i]
            rx = sx+dx[i]
            if ry >= n or ry < 0 or rx >= m or rx < 0: continue
            if g[ry][rx] == 0: continue
            if g[ry][rx] == 1:
                q.append((ry, rx))
                g[ry][rx] = g[sy][sx] + 1                
    return g[n-1][m-1]
print(bfs(0,0))
