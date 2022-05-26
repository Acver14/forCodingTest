import sys
input = sys.stdin.readline

n = int(input())

arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))
    
ans = 0
def dfs(idx, sum):
    global ans
    if idx >= n:
        ans = max(ans, sum)
        return
    
    dfs(idx+1, sum)
    dfs(idx+2, sum+arr[idx][2])

dfs(0, 0)
print(ans)