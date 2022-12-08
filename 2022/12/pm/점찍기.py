def solution(k, d):
    answer = 0
    D = d**2
    for x in range(0, d+1, k):
        y = int((D-x**2)**(1/2))
        answer += int(y//k)+1
    
    return answer