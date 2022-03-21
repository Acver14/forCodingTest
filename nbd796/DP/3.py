n, m = map(int, input().split())
arr = [0] * (n)
d = [10001] * (m+1)

for i in range(1, n+1):
    arr[i-1] = int(input())
    
arr.sort()

d[0] = 0
for i in range(1, m+1):
    for a in arr:
        if i-a < 0: continue
        d[i] = min([d[i], d[i-a]+1])
        
if d[m]==10001:
    print(-1)
else:
    print(d[m])

d[0] = 0
for i in range(n):
    for j in range(arr[i], m+1):
        if d[j-arr[i]] != 10001:
            d[j] = min(d[j], d[j-arr[i]]+1)
            
if d[m]==10001:
    print(-1)
else:
    print(d[m])