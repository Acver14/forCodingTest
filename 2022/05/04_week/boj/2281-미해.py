import sys
input = sys.stdin.readline

n, m = map(int, input().split())
names = []
for _ in range(n):
    names.append(int(input()))
    
dp = [[-1] * 1001 for _ in range(1001)]

def sol(pos, num):
    if num == n:
        return 0
    
    ret = dp[pos][num]
    if ret != -1:
        return ret
    
    nn = m - pos + 2
    ret = sol(names[num]+2, num+1) + nn**2
    
    if pos + names[num] - 1 <= m:
        ret = min(ret, sol(pos + names[num] + 1, num+1))
    
    return ret

print(sol(names[0]+2, 1))