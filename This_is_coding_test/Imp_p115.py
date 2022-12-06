### 내 코드###
import sys
read = sys.stdin.readline

p = read()
y = int(p[1])
if p[0] == 'a':
    x = 1
elif p[0] == 'b':
    x = 2
elif p[0] == 'c':
    x = 3
elif p[0] == 'd':
    x = 4
elif p[0] == 'e':
    x = 5
elif p[0] == 'f':
    x = 6
elif p[0] == 'g':
    x = 7
elif p[0] == 'h':
    x = 8

dx = [-2, -1, 1, 2, 2, 1, -1, -2]
dy = [-1, -2, -2, -1, 1, 2, 2, 1]
cnt = 0
for i, j in zip(dx, dy):
    nx = x + i
    ny = y + j
    if nx < 1 or nx > 8 or ny < 1 or ny > 8:
        continue
    cnt += 1
print(cnt)


### 책 코드###

# 현재 나이트 위치 입력받기
input_data = input()
row = int(input_data[1])
col = int(ord(input_data[0]))- int(ord('a')) + 1
print(row, col)
# 나이트가 이동할 수 있는 8가지 방향
steps = [(-2, -1), (-1, -2), (1, -2), (2, -1), (2, 1), (1, 2), (-1, 2), (-2, 1)]

result = 0
for step in steps:
    n_row = row + step[0]
    n_col = col + step[1]
    if n_row >= 1 and n_row <=8 and n_col >= 1 and n_col <= 8:
        result += 1

print(result)

