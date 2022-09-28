def solution(n):
    answer = 0
    for i in range(2, 1000001):
        if n % i == 1:
            return i