n, m = map(int, input().split())
a = list(map(int, input().split()))

# k = max(a)

# for i in range(k, 0, -1):
#     s = 0
#     for j in a:
#         if j < i: continue
#         s += j-i
#     if s >= m:
#         print(i)
#         break

# binary search version
start = 0
end = max(a)

result = 0
while(start <= end):
    total = 0
    mid = (start + end) // 2
    for x in a:
        if x > mid:
            total += x - mid
        
    if total < m:
        end = mid - 1
    else:
        result = mid
        start = mid + 1
            
print(result)
