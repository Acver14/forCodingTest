n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
b.sort()
b.reverse()

for i in range(k):
    for j in range(n):
        if a[i] < b[j]: 
            a[i], b[j] = b[j], a[i]
            break

print(sum(a))

