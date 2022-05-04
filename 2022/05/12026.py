import sys
input = sys.stdin.readline

n = int(input())
road = list(input().rstrip())
dp = [{
    'B' : -1, 'O' : -1, 'J' : -1
} for _ in range(n)]

dp[0]['B'] = 0
for i in range(1, n):
    flag = 'B'
    if road[i] == 'B':
        flag = 'J'
    elif road[i] == 'O':
        flag = 'B'
    elif road[i] == 'J':
        flag = 'O'
        
    for j in range(i):
        if dp[j][flag] != -1 and (dp[i][road[i]] == -1 or dp[i][road[i]] > dp[j][flag] + (i-j)**2):
            dp[i][road[i]] = dp[j][flag] + (i-j)**2

print(dp[n-1][road[n-1]])