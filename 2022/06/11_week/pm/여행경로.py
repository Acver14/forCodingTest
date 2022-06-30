from collections import defaultdict

def dfs(node, vec, route):
    global n, answer
    if answer:
        return
    if len(route) == n+1:
        answer = route
    for v in vec[node]:
        temp = vec.copy()
        temp[node] = vec[node].copy()
        temp[node].remove(v)
        dfs(v, temp, route+[v])

def solution(tickets):
    global answer, n
    n = len(tickets)
    answer = []
    vec = defaultdict(list)
    for f, t in tickets:
        vec[f].append(t)
    for v in vec.values():
        v.sort()
    dfs('ICN', vec, ['ICN'])
    
    return answer