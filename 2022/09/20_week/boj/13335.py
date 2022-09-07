from collections import deque
N, W, L = map(int, input().split())
truck = list(map(int, input().split()))

onBridge = deque([])

ans = 0
times = deque([])
idx = 0
while True:
    if idx == N and not times:
        break
    if times and times[0] >= W:
        onBridge.popleft()
        times.popleft()
    if idx < N and sum(onBridge) + truck[idx] <= L:
        onBridge.append(truck[idx])
        times.append(0)
        idx += 1
    for i in range(len(times)):
        times[i] += 1
    ans += 1
print(ans)
    