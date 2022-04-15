from sys import stdin
from collections import deque, defaultdict
input = stdin.readline

while True:
    n, k = map(int, input().split())
    if n == 0 and k == 0: break
    arr = list(map(int, input().split()))
    tree = defaultdict(list)
    tree[arr[0]]
    root = arr[0]
    prev = arr[1]
    for i in range(1, len(arr)):
        if prev+1 < arr[i]:
            for j in range(i):
                if not tree[arr[j]]:
                    root = arr[j]
                    break
                    
        tree[root].append(arr[i])
        prev = arr[i]
    print(tree)
    q = deque()
    q.append((arr[0], 0))
    visited = defaultdict(bool)
    visited[arr[0]] = True
    ans = 0
    find_key = 0
    ans = defaultdict(int)
    while q:
        node = q.popleft()
        print(node)
        num = node[0]
        if node[0] == k: find_key = node[1]
        ans[node[1]] += 1
        for i in tree[num]:
            if not visited[i]:
                visited[i] = True
                q.append((i, node[1]+1))
    print(find_key)
    print(ans)
    print(ans[find_key]-1)
            