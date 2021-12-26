# https://www.acmicpc.net/problem/1874
# 스택 수열
# https://hongcoding.tistory.com/39
import sys

flag = 0
stack = []
ans = []
cur = 1
n = int(sys.stdin.readline())
for _ in range(n):
    num = int(sys.stdin.readline())
    while cur <= num:
        stack.append(cur)
        ans.append("+")
        cur += 1

        if stack[-1] == num:
            stack.pop()
            ans.append("-")
        else:
            print("NO")
            flag = 1
            break
        if flag == 0:
            for i in ans:
                print(i)
