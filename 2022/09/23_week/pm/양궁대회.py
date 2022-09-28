def solution(n, info):
    global answer, score
    answer = []
    score = -1
    dfs(n, 0, info, [0 for _ in range(11)])
    if score > 0:
        return answer
    else:
        return [-1]

def calScore(apeach, lion):
    lscore, ascore = 0, 0
    for i in range(11):
        if lion[i] == apeach[i] == 0:
            continue
        elif lion[i] <= apeach[i]:
            ascore += 10-i
        elif lion[i] > apeach[i]:
            lscore += 10-i
    return lscore - ascore

def dfs(n, idx, apeach, lion):
    global answer, score
    if n < 0:
        return
    if idx > 10:
        diff = calScore(apeach, lion)
        if diff <= 0:
            return
        if diff > score:
            score = diff
            answer = lion.copy()
            answer[10] += n            
        return
    lion[10-idx] = apeach[10-idx] + 1
    dfs(n-lion[10-idx], idx+1, apeach, lion)
    lion[10-idx] = 0
    dfs(n, idx+1, apeach, lion)