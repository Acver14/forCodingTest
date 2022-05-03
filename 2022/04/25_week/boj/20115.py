import sys
input = sys.stdin.readline

n  = int(input())
drink = list(map(int, input().split()))

d = max(drink)
drink.remove(d)

for i in drink:
    d += i/2
print(d)