def solution(n, computers):
    answer = 0
    vec = [[] for _ in range(n)]
    visited = [False] * n
    for i in range(n):
        for idx, val in enumerate(computers[i]):
            if val and i != idx:
                vec[i].append(idx)
    
    for i in range(n):
        if not visited[i]:
            q = []
            q.append(i)
            visited[i] = True
            answer += 1
            while q:
                node = q.pop(0)
                for v in vec[node]:
                    if not visited[v]:
                        visited[v] = True
                        q.append(v)
    return answer