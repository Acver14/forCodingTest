import heapq as hq
def solution(scoville, K):
    answer = -1
    
    cnt = 0
    hq.heapify(scoville)
    while len(scoville) > 1:
        k = hq.heappop(scoville)
        if k >= K:
            answer = cnt
            break
        cnt += 1
        k += hq.heappop(scoville) * 2
        hq.heappush(scoville, k)
    if scoville[0] >= K:
        answer= cnt
    return answer