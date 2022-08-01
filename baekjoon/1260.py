#https://www.acmicpc.net/problem/1260

from collections import deque

n, m, v = map(int, input().split())

g = [[] for _ in range(n+1)]
# print(g)

def dfs(v):
    visited[v] = True
    print(v, end= ' ')
    for i in g[v]:
        if not visited[i]:
            dfs(i)
    
def bfs(v):
    q = deque([v])
    visited[v] = True
    while q:
        n = q.popleft()
        print(n, end=' ')
        for i in g[n]:
            if not visited[i]:
                q.append(i)
                visited[i] = True

for i in range(m):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

for i in range(1, n+1):
    g[i].sort()

visited = [False] * (n+1)
dfs(v)
visited = [False] * (n+1)
print(end='\n')
bfs(v)
