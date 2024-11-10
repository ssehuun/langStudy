s = input()
dic = {}

for i in s:
    if i.islower():
        i = chr(ord(i)-32)
    if i not in dic:
        dic[i] = 1
    else:
        dic[i] += 1

li = sorted(dic.items(), key=lambda x : x[1], reverse=True)

if len(li) > 1:
    if li[0][1] != li[1][1]:
        print(li[0][0])
    else:
        print('?')
else:
    print(li[0][0])