import sys

input = sys.stdin.readline
li = []
for _ in range(10):
    A = int(input())
    B = A % 42
    if B not in li:
        li.append(B)
print(len(li))