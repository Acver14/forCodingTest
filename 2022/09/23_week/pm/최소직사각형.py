def solution(sizes):
    answer = 0
    w, h = 0, 0
    for s in sizes:
        w, h = max(w, max(s)), max(h, min(s))
    
    return w*h