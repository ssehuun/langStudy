import sys

input = sys.stdin.readline
N = int(input())

jumsu = list(map(int, input().split()))
m = max(jumsu)

new = []
for i in jumsu:
    new.append(i/m*100)

print(sum(new) / len(new))