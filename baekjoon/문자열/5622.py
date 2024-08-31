import sys

W = sys.stdin.readline()
li_2 = [
    ("ABC", 3),
    ("DEF", 4),
    ("GHI", 5),
    ("JKL", 6),
    ("MNO", 7),
    ("PQRS", 8),
    ("TUV", 9),
    ("WXYZ", 10)
]
sum = 0
for i in W:
    for j in range(0, len(li_2)):
        idx = li_2[j][0].find(i)
        if idx != -1:
            sum += li_2[j][1]
print(sum)
