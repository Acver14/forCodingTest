def isPrime(n):
    for i in range(2, int(n**(1/2))+1):
        if n % i == 0:
            return False
    return True

def solution(n, k):
    answer = 0
    num = ''
    while n > 0:
        num = str(n%k) + num
        n //= k
        
    arr = num.split('0')
    for a in arr:
        if a == '1' or a == '':
            continue
        if isPrime(int(a)):
            answer+=1
    return answer