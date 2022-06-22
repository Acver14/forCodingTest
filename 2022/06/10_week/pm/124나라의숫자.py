def solution(n):
    s = ''
    while n > 0:
        r = n % 3
        n //= 3
        
        if r == 0:
            s = '4' + s
            n -= 1
        else:
            s = str(r) + s
    
    return s