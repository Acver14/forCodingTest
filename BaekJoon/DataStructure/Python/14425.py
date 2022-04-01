from sys import stdin
input = stdin.readline

n, m = map(int, input().strip().split())
string = input().strip()

ans = 0
for i in range(m):
    t = input().strip()
    if t in string:
        ans += 1
    
print(ans)