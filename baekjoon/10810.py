import sys

input = sys.stdin.readline
N, M = map(int, input().split())
li = [0 for i in range(N+1)]

for _ in range(M):
    a, b, c = map(int, input().split())
    for i in range(a, b+1):
        li[i] = c
    #print("li: ", li)

for i in li[1:]:
    print(i, end=" ")
