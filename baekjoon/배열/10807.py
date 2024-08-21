import sys

input = sys.stdin.readline
N = int(input())
li = []
li = list(map(int, input().split()))
    
v = int(input())
print(li.count(v))

