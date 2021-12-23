# https://www.acmicpc.net/problem/4673
# 셀프넘버
# 수학, 구현, 브루트포스

arr = [0]*10010

def d(num):
    if num > 10000:
        return
    str_num = list(map(int, list(str(num))))
    str_num.append(num)
    total = sum(str_num)
    if total > 10000:
        return
    # print(str(num)+": ", total)
    arr[total] = 1 #self number가 있다로 체크
    d(total)

for i in range(1, 10000):
    if arr[i] == 1:
        continue
    else:
        d(i)

for i in range(1, 10000):
    if arr[i] == 0:
        print(i)
