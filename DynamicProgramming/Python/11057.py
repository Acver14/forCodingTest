#2021.07.20
n = int(input())

D = [[0 for col in range(10)] for row in range(1001)]

for i in range(10):
    D[1][i] = 1
    
for i in range(2, n + 1):
    for j in range(10):
        for k in range(j+1):
            D[i][j] += D[i-1][k]
        D[i][j] %= 10007

ans = 0
for i in range(10):
    ans += D[n][i]
    
print(ans%10007)