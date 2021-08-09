#2021.07.23
n = int(input())

for i in range(n-1, -1, -1):
    for j in range(n):
        if i-1 < j: print('*', end='')
        print(' ', end='')
    print()