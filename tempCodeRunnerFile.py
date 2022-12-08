from collections import defaultdict
import heapq as hq
# jobs : 요청시각/걸리는시각/분류번호/중요도
def solution(jobs):
    done = []
    works = [[0, 0, 0, 0] for _ in range(jobs[-1][0]+1)]
    for j in jobs:
        works[j[0]] = j
    add_cnt = defaultdict(int)
    doing = jobs[0]
    time = doing[0]+1
    add_cnt[doing[2]] = 1
    req = []
    cnt = 0
    while cnt != len(jobs):
        if time < len(works):
            if doing[2] == works[time][2]:
                doing[1] += works[time][1]
                add_cnt[doing[2]] += 1
            elif works[time][2] != 0:
                for r in req:
                        if r[2][2] == works[time][2]:
                            r[2][1] += works[time][1]
                            r[2][3] += works[time][3]
                            r[1] -= works[time][3]
                            add_cnt[r[2][2]] += 1
                            break
                else:
                    # req.append(works[time])
                    hq.heappush(req, [works[time][2], -works[time][3], works[time]])
                    add_cnt[works[time][2]] = 1
                # req = sorted(req, key=lambda x:(-x[3], x[2]))
        print(doing, req)
        if doing[0] + doing[1] <= time:
            if doing[2] != 0:
                if not (done and done[-1] == doing[2]):
                    done.append(doing[2])
                cnt += add_cnt[doing[2]]
                add_cnt[doing[2]] = 1
            if req:
                doing = hq.heappop(req)[2]
                doing[0] = time
            else:
                doing = [time, 0, 0, 0]
        time += 1
    return done