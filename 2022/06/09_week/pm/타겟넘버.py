def dfs(idx, numbers, target, _sum):
    ret = 0
    if idx == len(numbers):
        if _sum == target:
            return 1
        return 0
    ret += dfs(idx+1, numbers, target, _sum+numbers[idx])
    ret += dfs(idx+1, numbers, target, _sum-numbers[idx])
    return ret

def solution(numbers, target):
    answer = 0
    answer = dfs(0, numbers, target, 0)
    return answer