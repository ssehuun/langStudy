import sys

T = int(sys.stdin.readline())
li = []
for _ in range(T):
    a = input()
    li.append(a)

for i in li:
    print(f"{i[0]}{i[-1]}")