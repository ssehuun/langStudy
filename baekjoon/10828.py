# https://www.acmicpc.net/problem/10828
# 스택

import sys

stack = []
a = int(sys.stdin.readline())
for i in range(0, a):
    li = list(sys.stdin.readline().split())
    if li[0] == "push":
        stack.append(li[1])
    elif li[0] == "top":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[-1])
    elif li[0] == "size":
        print(len(stack))
    elif li[0] == "pop":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())
    elif li[0] == "empty":
        if len(stack) == 0:
            print(1)
        else:
            print(0)
