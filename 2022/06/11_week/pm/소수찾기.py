from itertools import permutations
def setPrime(n):
    global isPrime
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, (n+1)//2+1):
        if isPrime[i]:
            for j in range(2, n+1):
                if i*j >= (n+1):
                    break
                isPrime[i*j] = False
                
def solution(numbers):
    global isPrime, answer
    answer = 0
    numbers = list(numbers)
    numbers.sort(reverse=True)
    target = int(''.join(numbers))
    isPrime = [True]*(target+1)
    perm = set()
    for i in range(1, len(numbers)+1):
        for p in permutations(numbers, i):
            perm.add(int(''.join(p)))
    setPrime(target)
    for p in perm:
        if isPrime[p]:
            answer+=1
    
    return answer