# https://www.acmicpc.net/problem/10773
# 제로
import sys

stack = []
n = int(sys.stdin.readline())
for _ in range(n):
    a = int(sys.stdin.readline())
    if a != 0:
        stack.append(a)
    else:
        stack.pop()
        print(sum(stack))
