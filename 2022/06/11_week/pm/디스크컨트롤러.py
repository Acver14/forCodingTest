import heapq

def solution(jobs):
    answer = 0
    n = len(jobs)
    time = []
    cur_time = 0
    while jobs:
        start, idx, job = -1, -1, 1001
        for i, [s, t] in enumerate(jobs):
            if s <= cur_time:
                if job > t:
                    job = t
                    idx = i
                    start = s
        if idx == -1:
            cur_time += 1
            continue
        jobs.pop(idx)
        cur_time += job
        time.append(cur_time-start)
    return sum(time)//n