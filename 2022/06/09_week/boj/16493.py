n, m = map(int, input().split())
arr = []
for _ in range(m):
    arr.append(list(map(int, input().split())))
    
ans = 0
def dfs(idx, sum, days):
    global ans
    if days > n:
        return
    ans = max(ans, sum)
    if idx >= m:
        return
    dfs(idx+1, sum+arr[idx][1], days+arr[idx][0])
    dfs(idx+1, sum, days)
dfs(0, 0, 0)
print(ans)