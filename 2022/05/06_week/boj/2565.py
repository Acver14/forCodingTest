import sys
from collections import defaultdict

input = sys.stdin.readline

n = int(input())
arr = [0 for _ in range(501)]
m = 0

for i in range(1, n+1):
    s, e = map(int, input().split())
    arr[s] = e
    m = max(m, max(s, e))

dp = [0 for _ in range(n)]