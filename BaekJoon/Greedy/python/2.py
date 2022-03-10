str = input()

ans = 0
for i in range(len(str)):
    num = int(str[i])
    if num <= 1 or ans <= 1:
        ans += num
    else:
        ans *= num
        
print(ans)