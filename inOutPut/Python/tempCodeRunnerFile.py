#2021.07.23
n = int(input())

for i in range(n):
    for j in range(0, 2*n-1):
        if i <= j and 2*n-i-1 > j: print('*', end='')
        elif 2 * n - i * 2 - 1 < j: break
        else: print('-', end='')
    print()
    
for i in range(n-2, -1, -1):
    for j in range(0, 2*n-1):
        if i <= j and 2*n-i-1 > j: print('*', end='')
        elif 2 * n - i * 2 - 1 < j: break
        else: print('-', end='')
    print()