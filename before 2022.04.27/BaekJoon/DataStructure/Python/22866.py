n = int(input())
arr = list(map(int, input().split()))
ans = [0]*n
near = [-1]*n

stk = []
for i in range(n):
    if stk:
        while stk and stk[-1][0] <= arr[i]:
            stk.pop()
    ans[i] += len(stk)
    if stk and (abs(near[i]-i) > abs(stk[-1][1]-i) or near[i]==-1): near[i] = stk[-1][1]
    stk.append([arr[i], i])


stk = []
for i in range(n-1, -1, -1):
    if stk:
        while stk and stk[-1][0] <= arr[i]:
            stk.pop()
    ans[i] += len(stk)
    if stk and (abs(near[i]-i) > abs(stk[-1][1]-i) or near[i]==-1): near[i] = stk[-1][1]
    stk.append([arr[i], i])

for i in range(n):
    if ans[i] > 0:
        print(ans[i], near[i]+1)
    else:
        print(0)