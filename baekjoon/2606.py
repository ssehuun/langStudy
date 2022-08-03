#https://www.acmicpc.net/problem/2606

from collections import deque

n = int(input())
v = int(input())

g = [[] for _ in range(n+1)]
for _ in range(v):
    n1, n2 = map(int, input().split())
    g[n1].append(n2)
    g[n2].append(n1)

visited = [False] * (n+1)

def bfs(n):
    q = deque()
    q.append(n)
    visited[n] = True
    while q:
        s = q.popleft()
        for i in g[s]:
            if visited[i] == False:
                q.append(i)
                visited[i] = True
    return visited.count(True)-1

print(bfs(1))
