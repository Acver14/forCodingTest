def sol():
    n , k = map(int, input().split())
    for i in range(1, n+1):
        data = str(i)
        if len(data) >= k:
            print(data[k-1])
            return
        k -= len(data)
    print(-1)
sol()