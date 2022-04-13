from sys import stdin
from collections import deque

input = stdin.readline

n = int(input().rstrip())
arr = list(map(int, input().rstrip().split()))
rm = int(input().rstrip())
tree = [[] for _ in range(n)]
root = 0
first_ans = 0
for i in range(len(arr)):
    if arr[i] != -1 and i != rm:
        tree[arr[i]].append(i)
    elif arr[i] == -1:
        root = i

if rm == root:
    print(0)
    exit()

visited = [False]*n
q = deque([])
q.append(root)
visited[root] = True
ans = 0
# tree.remove(tree[rm])
while q:
    node = q.popleft()
    if not tree[node]:
        ans+=1
        visited[i] = True
        continue
    for i in tree[node]:
        if not visited[i]:
            q.append(i)
            visited[i] = True
        

print(ans)