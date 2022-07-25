from sys import stdin
input = stdin.readline
T = int(input())

def isPal(S):
    left = 0
    right = len(S)-1
    while left < right:
        if S[left] == S[right]:
            left += 1
            right -= 1
        else:
            return min(isPseudo(S, left+1, right), isPseudo(S, left, right-1))
    return 0

def isPseudo(S, left, right):
    while left < right:
        if S[left] == S[right]:
            left += 1
            right -= 1
        else:
            return 2
    return 1

for _ in range(T):
    print(isPal(input().rstrip()))