import sys

input = sys.stdin.readline
N, M = map(int, input().split())

li = [i for i in range(1, N+1)]

for _ in range(M):
    i, j = map(int, input().split())
    a = li[i-1:j]
    a.reverse()
    li[i-1:j] = a

for i in li:
    print(i, end=" ")
