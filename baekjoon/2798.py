# https://www.acmicpc.net/problem/2798
# 블랙잭

num1, num2 = map(int, input().split())
sum = num2
li = list(map(int, input().split()))
li.sort()

def func():
    ans = 0
    for i in range(0, len(li)-2):
        for j in range(i+1, len(li)-1):
            for k in range(j+1, len(li)):
                if sum > li[i]+li[j]+li[k]:
                    if ans < li[i]+li[j]+li[k]:
                        ans = li[i]+li[j]+li[k]
                        continue
                    elif sum == li[i]+li[j]+li[k]:
                        return sum # 중간에 return을 하기위해 함수생성
    return ans

print(func())
