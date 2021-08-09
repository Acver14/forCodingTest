#2021.07.21
x, y = input().split()
x = int(x)
y = int(y)

ans = [ "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
for i in range(1, x):
    #1, 3, 5, 7, 8, 10, 12 = > 31
    if(i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12):
        y += 31
    elif(i == 2):
        y += 28
    else:
        y += 30
print(ans[y%7])
