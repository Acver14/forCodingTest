n = int(input())
l = list(map(int, input().split()))

l.sort()

cnt = 0
x = 0
for i in l:
    x += 1
    if x >= l[i]:
        cnt += 1
        x = 0
    
print(cnt)