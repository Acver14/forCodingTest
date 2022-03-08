# str = input()
# n = int(str.split(' ')[0])
# k = int(str.split(' ')[1])

# cnt = 0
# while True:
#     if n==1:
#         print(cnt)
#         break
#     if n % k == 0:
#         n //= k
#     else:
#         n -= 1
#     cnt += 1

n, k = map(int, input().split())

cnt = 0

while True:
    target = (n // k) * k
    cnt += (n - target)
    n = target
    
    if n < k:
        break
    
    cnt += 1
    n //= k
    
cnt += (n-1)
print(cnt)
    