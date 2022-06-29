def solution(answers):
    answer = []
    soo = [
        [1, 2, 3, 4, 5],
        [2, 1, 2, 3, 2, 4, 2, 5],
        [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    ]
    idx = [0, 0, 0]
    correct = [0, 0, 0]
    for ans in answers:
        for i in range(3):
            if ans == soo[i][idx[i]]:
                correct[i] += 1
            idx[i] += 1
            if idx[i] >= len(soo[i]):
                idx[i] = 0
    _max = max(correct)
    for i, v in enumerate(correct):
        if v == _max:
            answer.append(i+1)
            
    return answer