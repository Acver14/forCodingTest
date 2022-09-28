from collections import deque

def solution(n, m, x, y, r, c, k):
    answer = ''
    route_list = []
    route_set = set()
    x-=1
    y-=1
    r-=1
    c-=1
    mv = [[1,0], [0,-1], [0,1], [-1,0]]
    rkey = ['d', 'l', 'r', 'u']
    q = deque([[x, y, 0, '']])
    candidate = ''
    while q:
        tx, ty, cost, route = q.popleft()
        if cost > k:
            continue
        for i, v in enumerate(mv):
            nx, ny = tx+v[0], ty+v[1]
            if k - (cost+1) < abs(r-nx) + abs(c-ny):
                continue
            
            if 0 <= nx < n and 0 <= ny < m:
                nroute = route+rkey[i]
                if nroute not in route_set:
                    if cost+1 == k:
                        if nx == r and ny == c:
                            return nroute
                        continue

                    q.append([nx, ny, cost+1, nroute])
                    route_set.add(nroute)
                    break
    return "impossible"