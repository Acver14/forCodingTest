from sys import stdin
input = stdin.readline

n, m = map(int, input().strip().split())
string = []
for i in range(n):
    string.append(input().strip())

ans = 0
for i in range(m):
    t = input().strip()
    if t in string:
        ans += 1
    
print(ans)

# import sys
# I=sys.stdin.readline
# N,M=map(int,I().split())
# A={I().rstrip() for _ in [0]*N}
# print(sum([1*(I().rstrip() in A) for _ in [0]*M]))