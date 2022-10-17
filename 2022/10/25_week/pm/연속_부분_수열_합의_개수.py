import sys
sys.setrecursionlimit(100000)
def solution(elements):
    answer = 0
    global sub
    sub = set([])
    for i in range(len(elements)):
        dfs(i, 0, 0, elements)
        
    return len(sub)

def dfs(idx, _sum, cnt, elements):
    global sub
    if idx >= len(elements):
        idx = 0
    if cnt == len(elements):
        return
    sub.add(_sum+elements[idx])
    dfs(idx+1, _sum+elements[idx], cnt+1, elements)