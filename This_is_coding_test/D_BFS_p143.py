####### DFS - 음료수 얼려 먹기 (책코드) #######
# 세로N, 가로M

N, M = map(int, input().split())
m = []
for _ in range(N):
    m.append(list(map(int, input())))

def dfs(y, x):
    if y <= -1 or y >= N or x <= -1 or x >= M:
        return False
    if m[y][x] == 0:
        m[y][x] = 1
        dfs(x-1, y)
        dfs(x, y+1)
        dfs(x+1, y)
        dfs(x, y-1)
        return True
    return False

result = 0
for i in range(N):
    for j in range(M):
        if dfs(i, j) == True:
            result += 1

print(result)

####### BFS - 음료수 얼려 먹기 (내코드) #######
from collections import deque
# 세로N, 가로M
N, M = map(int, input().split())
m = []
for _ in range(N):
    m.append(list(map(int, input())))

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
result = 0

def bfs(y, x):    
    q = deque()
    q.append((y, x))
    while q:
        y, x = q.popleft()
        m[y][x] = 1
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if ny <= -1 or ny >= N or nx <= -1 or nx >= M: continue
            if m[ny][nx] == 0:
                q.append((ny, nx))
    
for i in range(N):
    for j in range(M):
        if m[i][j] == 0:
            bfs(i, j)
            result += 1
print(result)
