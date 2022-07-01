def solution(citations):
    answer = 0
    citations.sort(reverse = True)
    h = citations[0]
    while True:
        cnt = 0
        for c in citations:
            if c >= h:
                cnt += 1
        if cnt >= h and len(citations) - cnt <= h:
            return h
        h-=1
    return answer