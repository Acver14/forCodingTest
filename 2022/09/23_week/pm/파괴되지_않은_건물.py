def solution(board, skill):
    answer = 0
    N, M = len(board), len(board[0])
    arr = [[0 for _ in range(M+1)] for _ in range(N+1)]
    for atack, r1, c1, r2, c2, degree in skill:
        if atack == 1:
            degree *= -1
        arr[r1][c1] += degree
        arr[r1][c2+1] -= degree
        arr[r2+1][c2+1] += degree
        arr[r2+1][c1] -= degree
    for i in range(N):
        for j in range(M):
            arr[i][j+1] += arr[i][j]
    for j in range(M):
        for i in range(N):
            arr[i+1][j] += arr[i][j]
            
    for i in range(N):
        for j in range(M):
            if arr[i][j] + board[i][j] > 0:
                answer += 1
                
    return answer
