import sys
input = sys.stdin.readline

t = int(input())

def fact(n):
    ret = 1
    while n > 1:
        ret *= n
        n-=1
    return ret
        

for _ in range(t):
    n, m = map(int, input().split())
    
    ans = int(fact(m) / (fact(m-n) * fact(n)))
    print(ans)