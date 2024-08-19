import sys

input = sys.stdin.readline
li = []
for _ in range(9):
    i = int(input())
    li.append(i)
print(max(li))
print(li.index(max(li))+1)

