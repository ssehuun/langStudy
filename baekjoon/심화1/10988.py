s = input()

i = 0
while i <= int(len(s)/2):
    if s[i] != s[len(s)-1-i]:
        print(0)
        break
    else:
        i = i + 1
        if i >= int(len(s)/2):
            print(1)
            break