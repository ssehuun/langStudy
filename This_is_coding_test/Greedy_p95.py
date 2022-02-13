# 그리디 - 큰 수의 법치(p92)
# M의 조건이 100억 이상일때도 가능한 수학적 풀이법

N, M, K = map(int, input().split())

li = list(map(int, input().split()))
li.sort(reverse=True)

# 가장 큰 수가 더해지는 횟수 계산
cnt = int(M/(K+1)) * K
cnt += M % (K+1)

result = 0
result += (cnt) * li[0] # 가장 큰 수 더하기
result += (M-cnt) * li[1] # 두번째로 큰 수 더하기

print(result)
