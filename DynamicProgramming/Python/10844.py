#2021.07.16

D = [[0 for col in range(101)] for row in range(11)]
MOD = 1000000000

n = int(input())

for i in range(1, 10):
    D[1][i] = 1

for i in range(2, n+1):
    D[i][0] = D[i-1][1] % MOD
    D[i][9] = D[i-1][8] % MOD
    for j in range(1, 9):
        D[i][j] = (D[i-1][j-1] + D[i-1][j+1]) % MOD
    
ans = 0
for i in range(0, 10):
    ans += D[n][i]
    
print(ans)