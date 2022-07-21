import sys
S = list(input())
T = list(input())

ans = 0
while len(T) >= len(S):
    if T == S:
        ans = 1
    if T[-1] == 'A':
        T = T[:-1]
        continue
    elif T[-1] == 'B':
        T = T[:-1][::-1]
        continue
print(ans)