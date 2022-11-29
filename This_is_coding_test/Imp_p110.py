import sys
read = sys.stdin.readline

N = int(read())
plans = input().split()
x, y = 1, 1
# L, U, R, D
dy = [0, -1, 0, 1]
dx = [-1, 0, 1, 0]
move_types = ['L', 'U', 'R', 'D']

for plan in plans:
    for i in range(len(move_types)):
        if plan == move_types[i]:
            ny = y + dy[i]
            nx = x + dx[i]
    if ny < 1 or ny > N or nx < 1 or nx > N:
        continue
    y, x = ny, nx

print(y, x)
