import sys
input = sys.stdin.readline

k = [1 for _ in range(68)]
k[2] = 2
k[3] = 4
for i in range(4, 68):
    k[i] = k[i-1] + k[i-2] + k[i-3] + k[i-4]
    
t = int(input())
for i in range(t):
    n = int(input())
    print(k[n])