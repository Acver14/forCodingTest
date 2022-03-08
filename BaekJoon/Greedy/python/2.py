str = input()

ans = 0
for i in range(len(str)):
    if(str[i]=='0'):
        continue
    else:
        if(ans == 0): ans += int(str[i])
        else: ans *= int(str[i])
        
print(ans)