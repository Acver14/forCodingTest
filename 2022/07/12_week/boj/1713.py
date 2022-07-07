def findMin(q, log):
    n = 1001
    ret = 0
    for idx, val in enumerate(q):
        if log[val] < n:
            n = log[val]
            ret = idx
    return ret

n = int(input())
k = int(input())
arr = list(map(int, input().split()))
q = []
INF = 1001
log = [INF] * 101

for i in range(k):
    if arr[i] not in q:
        if len(q) >= n:
            idx = findMin(q, log)
            log[q[idx]] = INF
            q.pop(idx)
        log[arr[i]] = 0
        q.append(arr[i])
    log[arr[i]] += 1

print(' '.join(list(map(str, sorted(q)))))