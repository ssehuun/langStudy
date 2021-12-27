# https://www.acmicpc.net/problem/10610
# 30

num_li = list(map(int, input()))
num_li.sort()
total_sum = sum(num_li)

if num_li[0] == 0 and total_sum % 3 == 0:
    num_li.sort(reverse=True)
    print(''.join(str(e) for e in num_li))
else:
    print(-1)
