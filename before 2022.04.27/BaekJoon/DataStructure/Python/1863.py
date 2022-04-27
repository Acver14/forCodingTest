n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split()))[1])
    
stk = []

ans = 0
for i in arr:
    while stk and stk[-1] > i:
        if stk[-1]>0: ans+=1
        stk.pop()
    if stk and stk[-1] == i: continue
    stk.append(i)
while stk:
    if stk[-1]>0: ans+=1
    stk.pop()
    
print(ans)