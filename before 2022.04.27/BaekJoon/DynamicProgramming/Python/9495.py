#2021.07.23
testCase = int(input())

for t in range(testCase):
    n = int(input())
    D = [[0 for i in range(n+3)] for j in range(2)]

    for i in range(2):
            D[i][2:] = input().split()
            for j in range(2, n+2):
                D[i][j] = int(D[i][j])

    for i in range(3, n+2):
        D[0][i] += max(D[1][i-1], D[1][i-2])
        D[1][i] += max(D[0][i-1], D[0][i-2])
    print(max(D[0][n+1], D[1][n+1]))
    