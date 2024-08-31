import sys

T = int(sys.stdin.readline())
li = []
for _ in range(T):
    R, S = input().split()
    R = int(R)
    li.append((R, S))

for i in li:
    tmp = ""
    for j in i[1]:
        tmp += i[0] * j
    print(tmp)

"""
다른 풀이
S=int(input())
for i in range(S):
    a,b=input().split()
    a=int(a)
    for z in b:
        print(z*a,end="")
    print()
"""