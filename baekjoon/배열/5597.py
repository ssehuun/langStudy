import sys

li = [i for i in range(31)]

input = sys.stdin.readline
for _ in range(28):
    a = int(input())
    li[a] = 0

li2 = []
for i in li[1:]:
    if i != 0:
        li2.append(i)
# print("li2: ", li2)
for j in li2:
    print(j)