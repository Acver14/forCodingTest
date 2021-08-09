#2021.07.22
n = int(input())

for i in range(n, 0, -1):
    for j in range(i):
        print('*', end='')
    print()