import sys
from collections import deque
input = sys.stdin.readline

n = int(input())

arr = []
for i in range(n):
    arr.append(list(map, int(input().split())))

INF = 2100000000
dp = [[INF]*(n) for _ in range(n)]
dp[0][0] = 0

for i in range(n):
    