import math
n = int(input())
m = int(input())

m -= n
ans = math.factorial(n+m-1)/(math.factorial(n-1)*math.factorial(m))
print(int(ans))