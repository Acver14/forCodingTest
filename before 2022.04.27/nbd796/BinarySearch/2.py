from bisect import bisect_left, bisect_right

n, x = map(int, input().split())
a = list(map(int, input().split()))

start = bisect_left(a, x)
end = bisect_right(a, x)

cnt = end - start
if cnt == 0: print(-1)
else: print(end - start)