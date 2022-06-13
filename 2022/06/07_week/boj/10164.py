import math

n, m, k = map(int, input().split())

dotN1 = (k-1)//m + 1
dotM1 = k - (dotN1-1)*m
dotN2 = n - (dotN1-1)
dotM2 = m - (dotM1-1)

if k == 0 :
    print((math.factorial(n+m-2)//(math.factorial(n-1)*math.factorial(m-1))))
else :
    first = (math.factorial(dotN1+dotM1-2)//(math.factorial(dotN1-1)*math.factorial(dotM1-1)))
    second = (math.factorial(dotN2+dotM2-2)//(math.factorial(dotN2-1)*math.factorial(dotM2-1)))
    print(first*second)
    
def find(x, y):
    dp = [[0]*(y+1) for _ in range(x+1)]
    for i in range(1, x+1):
        for j in range(1, y+1):
            if i == 1 and j == 1 :
                dp[i][j] = 1
                continue
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
    return dp[x][y]

if k == 0:
    print(find(n, m))
else:
    first = find(dotN1, dotM1)
    second = find(dotN2, dotM2)
    print(first*second)