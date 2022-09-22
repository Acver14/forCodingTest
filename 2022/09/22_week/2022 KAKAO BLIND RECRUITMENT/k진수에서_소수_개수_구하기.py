def solution(n, k):
    answer = 0
    p = ''
    while n != 0:
        p = str(n%k) + p
        n //= k
    arr = []
    for num in p.split('0'):
        if num.isdigit():
            if isPrime(int(num)):
                answer+=1
            
    return answer
    
def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(n**(1/2))+1):
        if n % i == 0:
            return False
    return True
    return prime