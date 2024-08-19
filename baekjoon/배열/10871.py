import sys

input = sys.stdin.readline
N, X = map(int, input().split())
li = list(map(int, input().split()))
for i in li:
    if i < X:
        print(i, end=" ")

