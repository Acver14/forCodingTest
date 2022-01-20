n = int(input())

for i in range(1, n+1):
    for j in range(1, 2 * n+1):
        if i >= j or 2*n-i+1 <= j: print('*', end='')
        else: print(' ', end='')
    print()
for i in range(n-1, 0, -1):
    for j in range(1, 2 * n+1):
        if i >= j or 2*n-i+1 <= j: print('*', end='')
        else: print(' ', end='')
    print()