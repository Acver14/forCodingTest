def solution(n, left, right):
    return [(i%n + 1 + max(i//n - i % n, 0)) for i in range(left, right+1)]