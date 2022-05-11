# 문제설명
# 김덕배는 산을 오르고 있으며, 산은 입구, 봉우리, 쉼터 로 구성되어 있다.

# Solution 함수는 int형 매개변수 1개, 2차원 벡터 1개, 1차원 벡터 2개로 이루어져 있다. (아래 입출력 예시 참고)

# 첫번째 int 형 매개변수 n은 산을 이루는 입구, 봉우리, 쉼터의 갯수의 총합
# 두번째 2차원 벡터 paths는  각 3개의 인덱스로 이루어져 있으며 설명은 아래와 같다
# paths[0] - 경로의 출발 번호
# paths[1] - 경로의 도착 번호
# paths[2] - 두 경로를 쉬는 시간 없이 이동하는데 걸리는 시간
# 1차원 벡터 gates는 산을 이루는 입구 번호가 적힌 벡터
# 1차원 벡터 summits는 산을 이루는 봉우리 번호가 적힌 벡터

# 김덕배가 산을 오르는 경로는 반드시 입구에서 시작하여 봉우리를 거치고 다시 원래 시작한 입구에서 끝나야 한다
# 또한 경로 중간에 다른 입구가 존재해서는 안되며, 입구는 반드시 경로의 맨 처음과 끝에 한번씩만 존재하며 그 번호는 일치해야 한다
# 산 봉우리는 한 곳만 방문 할 수 있으며, 봉우리는 경로에서 한 곳만 방문 해야한다.

# 이 때 등산을 할 때는 오직 입구, 봉우리, 쉽터에서만 휴식을 가질 수 있다. 등산 경로에서 쉼없이 이동하는 가장 긴 시간을 intensity라고 부른다. 

# 가장 작은 intensity를 가지는 경로가 여러개인 경우 그 중 봉우리 번호가 작은 경로를 선택한다

# 위 규칙을 만족하는 (intensity 값이 가장 작은 경로이며, 동일한 intensity값을 가지는 경로가 여러개인 경우 봉우리의 숫자가 가장 작은 경로) 
# 경로의 봉우리 값을 result 벡터의 0번 인덱스로, 그 경로의 intensity값을 1번 인덱스로 가지는 result 벡터를 반환하는 Solution함수를 만드시오


# 입출력 예시
# n	paths	                                                                                    gates	summits	    result
# 6	[[1, 2, 3], [2, 3, 5], [2, 4, 2], [2, 5, 4], [3, 4, 4], [4, 5, 3], [4, 6, 1], [5, 6, 1]]	[1, 3]	[5]	        [5, 3]
# 7	[[1, 4, 4], [1, 6, 1], [1, 7, 3], [2, 5, 2], [3, 7, 4], [5, 6, 6]]	                        [1]	    [2, 3, 4]	[3, 4]
# 7	[[1, 2, 5], [1, 4, 1], [2, 3, 1], [2, 6, 7], [4, 5, 1], [5, 6, 1], [6, 7, 1]]	            [3, 7]	[1, 5]	    [5, 1]
# 5	[[1, 3, 10], [1, 4, 20], [2, 3, 4], [2, 4, 6], [3, 5, 20], [4, 5, 6]]	                    [1, 2]	[5]	        [5, 6]
from collections import deque

n = 7
paths = [[1, 3, 10], [1, 4, 20], [2, 3, 4], [2, 4, 6], [3, 5, 20], [4, 5, 6]]
gates = [1, 2]
summits = [5]

graph = [[] for _ in range(n+1)]
for p in paths:
    graph[p[0]].append([p[1], p[2]])
    graph[p[1]].append([p[0], p[2]])

INF = 2100000000
ans = [-1, INF]

for g in graph:
    g.sort(key = lambda x :(x[1], x[0]))

for start in gates:
    visit = [-1 for _ in range(n+1)]
    q = deque([(start, [start])])
    while q:
        node, route = q.popleft()
        if node in summits:
            print(start, node, visit, route)
            intensity = -1
            for r in route:
                if intensity < visit[r]:
                    intensity = visit[r]
            if ans[1] > intensity:
                ans = [node, intensity]
            elif ans[1] == intensity:
                if ans[0] > node:
                    ans[0] = node
            continue
        
        for g in graph[node]:
            next = g[0]
            w = g[1]
            if visit[next] == -1 or visit[next] > w:
                visit[next] = w
                q.append((next, route+[next]))
            
print(ans)