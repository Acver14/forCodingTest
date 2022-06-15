n = int(input())

ans = 0
def dfs(sum, idx):
    global ans
    if idx == n:
        if sum % 3 == 0:
            ans += 1
        return
    dfs(sum * 10 + 0, idx + 1)
    dfs(sum * 10 + 1, idx + 1)
    dfs(sum * 10 + 2, idx + 1)
    
dfs(1, 1)
dfs(2, 1)
print(ans)