# 다음과 같이 import를 사용할 수 있습니다.
# import math

from collections import deque

def solution(garden):
    # 여기에 코드를 작성해주세요.
    q = deque([])
    mv = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    for i in range(len(garden)):
        for j in range(len(garden[i])):
            if garden[i][j] == 1:
                q.append((i, j))
    
    answer = 0
    while q:
        x, y = q.popleft()
        answer = garden[x][y]
            
        for i in range(4):
            nx, ny = x + mv[i][0], y + mv[i][1]
            if nx < 0 or nx >= len(garden) or ny < 0 or ny >= len(garden[0]):
                continue
            if garden[nx][ny] > 0:
                continue
            garden[nx][ny] = garden[x][y]+1
            q.append((nx, ny))
            
    return answer-1

# 아래는 테스트케이스 출력을 해보기 위한 코드입니다.
garden1 = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
ret1 = solution(garden1)

# [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret1, "입니다.")

garden2 = [[1, 1], [1, 1]]
ret2 = solution(garden2)

# [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret2, "입니다.")