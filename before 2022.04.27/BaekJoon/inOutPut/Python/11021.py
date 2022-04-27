#2021.07.16
n = int(input())

for i in range(n):
    a, b = input().split()
    print("Case #" + str(i+1) + ": " + str(int(a) + int(b)))