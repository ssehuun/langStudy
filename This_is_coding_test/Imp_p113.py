import sys
read = sys.stdin.readline

N = int(read())
# 00시 00분 00초
cnt = 0
for i in range(N+1):
    for j in range(60):
        for k in range(60):
            if '3' in str(k) or '3' in str(j) or '3' in str(i):
            # 책 풀이
            # if '3' in str(i)+str(j)+str(k):
                cnt += 1

print(cnt)
