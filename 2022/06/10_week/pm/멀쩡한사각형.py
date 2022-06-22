def gcd(a, b):
    i = min(a, b)
    while True:
        if a % i == 0 and b % i == 0:
            return i
        i -= 1
        
def solution(w,h):
    answer = 1
    g = gcd(w, h)
    nw, nh = w // g, h // g
    
    d = nw + nh - 1
    answer = w * h - d * (w // nw)
    return answer