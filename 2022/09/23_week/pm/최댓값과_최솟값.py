def solution(s):
    answer = ''
    arr = list(map(int, s.split()))
    
    return ' '.join([str(min(arr)), str(max(arr))])