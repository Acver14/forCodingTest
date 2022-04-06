from sys import stdin
from collections import defaultdict

input = stdin.readline

t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    arr1 = []
    arr1 = list(map(int,input().rstrip().split()))
    d = defaultdict(int)
    for i in arr1:
        d[i] = 1
    m = int(input().rstrip())
    arr2 = []
    arr2 = list(map(int,input().rstrip().split()))
    for i in arr2:
        print(d[i])      