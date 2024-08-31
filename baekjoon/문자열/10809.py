import sys

S = sys.stdin.readline()

li = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]

for i in li:
    if i in S:
        print(S.index(i), end=" ")
    else:
        print(-1, end=" ")

"""
다른 풀이
s=input()
for i in range(97,123):
    a=s.find(chr(i))
    print(a,end=' ')
"""