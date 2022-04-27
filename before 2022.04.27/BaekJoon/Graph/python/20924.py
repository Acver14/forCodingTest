import sys
from collections import deque
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

n, r = map(int, input().rstrip().split())
tree = [[] for _ in range(n+1)]
for _ in range(n-1):
    u, v, d = map(int, input().rstrip().split())
    tree[u].append((v, d))
    tree[v].append((u, d))

root = 0
visited = [False]*(n+1)
def dfs(node, leaf, isLeaf):
    global root, visited, r
    max_leaf = leaf
    if node == r and len(tree[node]) > 1:
        isLeaf = True
    if len(tree[node]) > 2:
        isLeaf = True
    for i in range(len(tree[node])):
        if not visited[tree[node][i][0]]:
            visited[tree[node][i][0]]= True
            if isLeaf:
                max_leaf = max(dfs(tree[node][i][0], leaf + tree[node][i][1], isLeaf), max_leaf)
            else:
                root += tree[node][i][1]
                max_leaf = max(dfs(tree[node][i][0], leaf, isLeaf), max_leaf)
                    
    return max_leaf

visited[r] = True
leaf = dfs(r, 0, False)
print(root, leaf)