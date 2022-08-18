import sys
D, n = map(int, input().split())
oven = list(map(int, input().split()))
pizza = list(map(int, input().split()))

for i in range(D-1):
    if oven[i] < oven[i+1]:
        oven[i+1] = oven[i]
 
cur = 0
for i in range(D-1, -1, -1):
    if pizza[cur] > oven[i]:
        continue
    
    cur += 1
    if cur >= n:
        print(i+1)
        sys.exit(0)
 
print(0)