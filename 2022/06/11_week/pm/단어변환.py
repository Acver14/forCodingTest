from collections import defaultdict

def check(s1, s2):
    cnt = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            cnt += 1
        if cnt > 1:
            return False
    if cnt == 1:
        return True
    else:
        return False

def solution(begin, target, words):
    if target not in words:
        return 0
    
    visited = defaultdict(bool)
    vec = defaultdict(list)
    for s1 in words:
        if check(s1, begin):
            vec[begin].append(s1)
    for s1 in words:
        for s2 in words:
            if check(s1, s2):
                vec[s1].append(s2)
    
    q = []
    q.append((begin, 0))
    visited[begin] = True
    while q:
        node, dist = q.pop(0)
        if node == target:
            return dist
        for v in vec[node]:
            if not visited[v]:
                visited[v] = True
                q.append((v, dist+1))
    return 0