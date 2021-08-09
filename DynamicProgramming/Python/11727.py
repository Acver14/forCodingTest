#2021.07.20
n = int(input())

D = [0 for i in range(1001)]

D[1] = 1
D[2] = 3
D[3] = 5

for i in range(4, n+1):
    D[i] = (D[i-1] + D[i-2]*2) % 10007
    
print(D[n])