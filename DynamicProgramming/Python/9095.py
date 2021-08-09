#2021.07.15
D = [1 for i in range(12)]

n = int(input())
D[1] = 1
D[2] = 2
D[3] = 4
for i in range(4, n+1):
    D[i] = D[i-1] + D[i-2] + D[i-3]
    
print(D[n])