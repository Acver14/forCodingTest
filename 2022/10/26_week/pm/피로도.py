import itertools
def solution(k, dungeons):
    global answer
    answer = -1
    perm = itertools.permutations([i for i in range(len(dungeons))], len(dungeons))
    for p in perm:
        stamina = k
        cnt = 0
        for i in p:
            if stamina >= dungeons[i][0]:
                stamina -= dungeons[i][1]
                cnt += 1
        answer = max(answer, cnt)
    return answer