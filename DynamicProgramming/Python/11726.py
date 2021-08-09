#2021.07.15
MOD = 10007
D = [0 for i in range(1003)]
D[0] = 100
D[1] = 1
D[2] = 2
n = int(input())

print(str(type(n))+'  '+str(n))

for i in range(3, n+1):
    D[i] = (D[i-1] + D[i-2])

print(D[n])