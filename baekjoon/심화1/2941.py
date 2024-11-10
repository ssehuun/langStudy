s = input()

cnt = 0
i = 0
while i < len(s):
    if s[i] == 'l':
        if i+1 < len(s) and s[i+1] == 'j':
            i += 2
            cnt += 1
        else:
            i += 1
            cnt += 1
    elif s[i] == 'c':
        if i+1 < len(s) and (s[i+1] == '=' or s[i+1] == '-'):
            i += 2
            cnt += 1
        else:
            i += 1
            cnt += 1
    elif s[i] == 'n':
        if i+1 < len(s) and s[i+1] == 'j':
            i += 2
            cnt += 1
        else:
            i += 1
            cnt += 1
    elif s[i] == 's':
        if i+1 < len(s) and s[i+1] == '=':
            i += 2
            cnt += 1
        else:
            i += 1
            cnt += 1
    elif s[i] == 'z':
        if i+1 < len(s) and s[i+1] == '=':
            i += 2
            cnt += 1
        else:
            i += 1
            cnt += 1
    elif s[i] == 'd':
        if i+1 < len(s) and s[i+1] == '-':
            i += 2
            cnt += 1
        elif i+2 < len(s) and s[i+1] == 'z' and s[i+2] == '=':
            i += 3
            cnt += 1
        else:
            i += 1
            cnt += 1
    else:
        i += 1
        cnt += 1
print(cnt)
