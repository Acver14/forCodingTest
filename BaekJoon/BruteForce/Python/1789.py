import sys
input = sys.stdin.readline

s = int(input())

n = 1
ans = 0
while True:
    ans += n
    
    if ans > s:
        print(n-1)
        break
    
    n+=1