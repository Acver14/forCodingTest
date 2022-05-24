import sys
input = sys.stdin.readline
MOD = 1000000000
sys.setrecursionlimit(1000000)

n = int(input())

k = 1000003
dp = [1000000001 for _ in range(k)]
dp[0] = 0
dp[1] = 1