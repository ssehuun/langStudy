### 책 코드
import sys
read = sys.stdin.readline

# 세로, 가로 크기 입력
N, M = map(int, read().split())

# 좌표 위치 y, x, 방향 입력
x, y, di = map(int, read().split())

# 방문했는지 안했는지 확인
d = [[0] * M for _ in range(N)]
d[x][y] = 1

# 바다(1), 육지(0) 맵 입력
m = []
for _ in range(N):
    m.append(list(map(int, read().split())))

# 북, 동, 남, 서
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

# 왼쪽으로회전
def turn_left():
    global di
    di -= 1
    if di == -1:
        di = 3

cnt = 1
turn_time = 0

while True:
    # 왼쪽으로 회전
    turn_left()
    nx = x + dx[di]
    ny = y + dy[di]
    # 회전 이후 정면에 가보지 않은 칸이 존재하는 경우 이동
    if d[nx][ny] == 0 and m[nx][ny] == 0:
        d[nx][ny] = 1
        x = nx
        y = ny
        cnt += 1
        turn_time = 0
        continue
    # 회전 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
    else:
        turn_time += 1
    # 네 방향 모두 갈 수 없는 경우
    if turn_time == 4:
        nx = x - dx[di]
        ny = y - dy[di]
        # 뒤로 갈 수 있다면 이동하기
        if m[nx][ny] == 0:
            x = nx
            y = ny
        # 뒤가 바다로 막혀있는 경우
        else:
            break
        turn_time = 0
print(cnt)
