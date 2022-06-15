n = int(input())
arr = []
for _ in range(n-1):
    arr.append(list(map(int, input().split())))
k = int(input())

ans = 10**9
def dfs(isK, idx, sum):
    global ans
    if sum >= ans or idx >= n:
        return
    if idx == n-1:
        ans = min(ans, sum)
        return
    dfs(isK, idx+1, sum+arr[idx][0])
    dfs(isK, idx+2, sum+arr[idx][1])
    if not isK:
        dfs(True, idx+3, sum+k)

dfs(False, 0, 0)
print(ans)