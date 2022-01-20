#2021.07.20
x = int(input())
count = 0
D = [0 for i in range(x+1)]

for i in range(2, x+1):
    _min = D[i-1] + 1
    if(i%3==0): _min = min(_min, D[int(i/3)] + 1)
    if(i%2==0): _min = min(_min, D[int(i/2)] + 1)
    D[i] = _min

print(D[x])

def min(x, y):
    if(x < y): return x
    else: return y