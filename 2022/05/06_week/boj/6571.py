
fibo = [1,1];t = 1
while fibo[-1] < 10**100:
    fibo.append(fibo[t]+fibo[t-1])
    t += 1

while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
            break
    aa,bb = 0,0
    for i in range(0,len(fibo)):
        if fibo[i] >= a and aa == 0:
            aa = i
        if fibo[i] > b and bb == 0:
            bb = i
    print(bb-aa)