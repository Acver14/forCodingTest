from sys import stdin

input = stdin.readline

na, nb = map(int, input().rstrip().split())
a = list(map(int, input().rstrip().split()))
b = list(map(int, input().rstrip().split()))

print(len(set(a) ^ set(b)))