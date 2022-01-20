#2021.07.16
n = int(input())

for i in range(n):
    a, b = input().split()
    print("Case #" + str(i+1) + ": " + a + " + " + b + " = " + str(int(a) + int(b)))