def dfs(depth):
    if depth == M:
        s = ' '.join(map(str, li))
        if s not in d:
            d[s] = 1
            print(s)
        return
    for i in range(N):
        if check[i]:
            continue
        li.append(nums[i])
        check[i] = 1
        dfs(depth+1)
        li.pop()
        check[i] = 0

N, M = map(int, input().split())
nums = sorted(map(int, input().split()))
d = {}
li = []
check = [0]*N
dfs(0)
print(d)