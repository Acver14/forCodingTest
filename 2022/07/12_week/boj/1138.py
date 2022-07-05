import enum
from itertools import permutations

answer = []
n = int(input())
arr = list(map(int, input().split()))

permutation = permutations([i for i in range(n)], n)

for perm in permutation:
    if answer:
        break
    for idx, val in enumerate(perm):
        cnt = 0
        for i in range(idx):
            if perm[i] > val:
                cnt += 1
        if cnt != arr[val]:
            answer = []
            break
        else:
            answer.append(val+1)
        
for a in answer:
    print(a, end = ' ')