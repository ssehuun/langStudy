import sys

chess = [1, 1, 2, 2, 2, 8]
li = list(map(int, sys.stdin.readline().split()))

for i, j in zip(chess,li):
    print(i-j, end=" ")
