####### BFS - 특정 거리의 도시 찾기 (내코드) #######

from collections import deque
# 도시 n, 도로 m, 최단거리 k, 출발도시 x
n, m, k, x = map(int, input().split())

g = [[] for _ in range(n+1)]

# a -> b 단방향 도로
for i in range(m):
    a, b = map(int, input().split())
    g[a].append(b)

# 방문 체크, 0이면 안간것, 0이 아니면 간것
v = [0] * (n+1)

def bfs(x):
    q = deque()
    q.append(x)
    while q:
        now = q.popleft() # 시작하는 도시 now
        for next in g[now]: # 도시 now에서 출발해서 도착하는 도시 next 순회
            if v[next] != 0: continue # 도착 도시 next에 이미 방문했으면 패스
            else:
                q.append(next)
                v[next] = v[now] + 1
        
bfs(x)

result = []
for i in range(len(v)):
    if v[i] == k:        
        result.append(i)

if len(result) == 0:
    print(-1)
else:
    for j in result:
        print(j)


"""
#### 테스트 코드 ####
Input
4 4 2 1
1 2
1 3
2 3
2 4
Output
4

Input
4 3 2 1
1 2
1 3
1 4
Output
-1

Input
4 4 1 1
1 2
1 3
2 3
2 4
Output
2
3
"""
