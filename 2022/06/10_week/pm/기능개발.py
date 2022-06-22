def solution(progresses, speeds):
    answer = []
    
    times = 0
    for i in range(len(progresses)):
        degree = progresses[i]
        s = speeds[i]
        spent_time = int((100 - degree) / s)
        if (100-degree)%s > 0:
            spent_time += 1
        if times >= spent_time:
            answer[-1] += 1
        else:
            answer.append(1)
            times = spent_time
    
    return answer