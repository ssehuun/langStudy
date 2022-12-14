####### BFS - 미로 탈출 (내코드) #######
from collections import deque
# 세로N, 가로M
N, M = map(int, input().split())
m = []

for _ in range(N):
    m.append(list(map(int, input())))

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def bfs(y, x):    
    q = deque()
    q.append((y, x))
    while q:
        y, x = q.popleft()        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if ny <= -1 or ny >= N or nx <= -1 or nx >= M: continue
            if m[ny][nx] != 1: continue
            if m[ny][nx] == 1:
                q.append((ny, nx))
                m[ny][nx] = m[y][x] + 1

bfs(0, 0)
print(m[N-1][M-1])
"""
### 검증 코드 ###
for i in range(N):
    for j in range(M):
        print(m[i][j], end=" ")
    print("\n")
"""
