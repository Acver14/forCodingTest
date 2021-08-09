#2021.07.23
n = int(input())

for i in range(n-1, 0, -1):
    for j in range(2*n-1):
        if j == i or j == 2 * (n-1) - i: print('*',end='')
        elif j > 2 * (n-1) - i: break
        else: print(' ', end='')
    print()
for i in range(2*n-1): print('*', end='')