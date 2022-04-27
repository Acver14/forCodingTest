t = int(input())

for test in range(t):
    n, m = map(int, input().split())
    d = [[-1] * m for i in range(n)]
    a = [[-1] * m for i in range(n)]
    temp = list(map(int, input().split()))
    for i in range(n):
        for j in range(m):
            a[i][j] = temp[i*m+j]

    for i in range(n):
        d[i][0] = a[i][0]
    for i in range(1,m):
        for j in range(n):
            d[j][i] = d[j][i-1] + a[j][i]
            if j-1 > 0:
                d[j][i] = max(d[j][i], d[j-1][i-1] + a[j][i])
            if j+1 < n:
                d[j][i] = max(d[j][i], d[j+1][i-1] + a[j][i])
                
    ans = -1
    for i in range(n):
        ans = max(d[i][m-1], ans)
    print(ans)

for tc in range(int(input())):
    n, m = map(int, input().split())
    array = list(map(int, input().split()))
    dp = []
    index = 0
    for i in range(n):
        dp.append(array[index:index+m])
        index += m
    for j in range(1, m):
        for i in range(n):
            if i == 0: left_up = 0
            else: left_up = dp[i-1][j-1]
            if i == n - 1: left_down = 0
            else: left_down = dp[i+1][j-1]
            left = dp[i][j-1]
            dp[i][j] = dp[i][j] + max(left_up, left_down, left)
    result = 0
    for i in range(n):
        result = max(result, dp[i][m-1])
    print(result)
