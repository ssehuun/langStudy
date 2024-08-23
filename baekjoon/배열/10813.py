import sys

input = sys.stdin.readline
N, M = map(int, input().split())
li = [i for i in range(N+1)]

for _ in range(M):
    a, b = map(int, input().split())
    li[a], li[b] = li[b], li[a]
    # print("li: ", li)

for i in li[1:]:
    print(i, end=" ")