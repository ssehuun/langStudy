import sys

input = sys.stdin.readline
N, M = map(int, input().split())
li = [i for i in range(N+1)]
li[-1] = 0

for _ in range(M):
    a, b, c = map(int, input().split())
    for i in range(a, b+1):
        li[i] = c
    print("li: ", li)

for i in li[1:]:
    print(i, end=" ")
