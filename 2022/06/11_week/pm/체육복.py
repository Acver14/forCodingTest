def solution(n, lost, reserve):
    answer = 0
    temp = set(lost) & set(reserve)
    for t in temp:
        lost.remove(t)
        reserve.remove(t)
        
    reserve.sort()
    lost.sort()
    
    for r in reserve:
        for l in lost:
            if l == r-1 or l == r+1:
                lost.remove(l)
    
    return n - len(lost)