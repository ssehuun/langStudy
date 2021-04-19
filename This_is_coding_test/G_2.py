# 곱하기 혹은 더하기
l = list(map(int, input()))

result = l[0]

for i in l[1:]:
    if result <=1 or i <= 1:
        result += i
    else:
        result *= i
        print(result)
