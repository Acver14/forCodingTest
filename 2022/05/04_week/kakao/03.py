# 문제설명
# 김덕배는 코딩스터디를 진행하고 있으며, 각 문제를 풀기 위해서는 alp(알고력)과 cop(코딩력)의 최소값을 가지고 있다.

# Solution 함수에게 2개의 int값과 1개의 2차원 벡터가 매개변수로 주어진다. (call by value) 
# 2개의 int형 매개변수는 각각 alp 와 cop로 초기 alp 값과 cop값을 결정한다

# Solution 함수로 전해지는 2차원 벡터 problems에는 각 문제에 대한 정보를 가지고 있으며, 각 인덱스에 대한 설명은 아래와 같다
# problems[0] - 문제를 해결하기 위한 alp
# problems[1] - 문제를 해결하기 위한 cop
# problems[2] - 문제를 해결하고 보상으로 얻는 alp
# problems[3] - 문제를 해결하고 보상으로 얻는 cop
# problems[4] - 문제를 해결하는데 걸리는 시간

# 추가적으로 alp 와 cop를 늘리기 위한 방법으로는 1시간을 투자하여 alp와 cop 둘 중 하나를 1 만큼 올릴 수 있다

# 한 문제를 어러번 풀 수도 있으며, 모든 문제를 한번씩 풀 필요는 없다

# 이때, 모든 문제를 풀기 위한 alp와 cop를 확보할 수 있는데 걸리는 최소 시간을 구하는 함수를 제작하여 result에 담아 반환하는 solution 함수를 만드시오

# 입출력 예시
# alp	cop	    problems	                                                    result
# 10	10	    [[10,15,2,1,2],[20,20,3,3,4]]	                                15
# 0	    0	    [[0,0,2,1,2],[4,5,3,1,2],[4,11,4,0,2],[10,4,0,4,2]]	            13
from collections import deque

alp, cop = 0, 0
problems = [[0,0,2,1,2],[4,5,3,1,2],[4,11,4,0,2],[10,4,0,4,2]]
maxAlp, maxCop = 0, 0
for i in range(len(problems)):
    if maxAlp < problems[i][0]:
        maxAlp = problems[i][0]
    if maxCop < problems[i][1]:
        maxCop = problems[i][1]

q = deque([(alp, cop)])
INF = 2100000000
times = [[INF] * 1000 for _ in range(1000)]
times[alp][cop] = 0
ans = INF
while q:
    a, c = q.popleft()
    if a >= maxAlp * 2 and c >= maxCop * 2:
        break
    if a >= maxAlp and c >= maxCop:
        if ans > times[a][c]:
            ans = times[a][c]
    for p in problems:
        if a >= p[0] and c >= p[1]:
            if times[a+p[2]][c+p[3]] > times[a][c] + p[4]:
                times[a+p[2]][c+p[3]] = times[a][c] + p[4]
                q.append((a+p[2], c+p[3]))
    if times[a+1][c] > times[a][c]+1:
        times[a+1][c] = times[a][c]+1
        q.append((a+1, c))
    if times[a][c+1] > times[a][c]+1:
        times[a][c+1] = times[a][c]+1
        q.append((a, c+1))
        
print(ans)