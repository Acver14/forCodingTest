from collections import defaultdict
def solution(survey, choices):
    answer = ''
    score = defaultdict(int)
    for idx, val in enumerate(survey):
        s = 4 - choices[idx]
        if val[0] == 'A':
            score['A'] += s
        elif val[0] == 'N':
            score['A'] -= s
        elif val[0] == 'C':
            score['C'] += s
        elif val[0] == 'F':
            score['C'] -= s
        elif val[0] == 'J':
            score['J'] += s
        elif val[0] == 'M':
            score['J'] -= s
        elif val[0] == 'R':
            score['R'] += s
        elif val[0] == 'T':
            score['R'] -= s
    item = ['R', 'C', 'J', 'A']
    for key in item:
        if key == 'A':
            if score[key] >= 0:
                answer += 'A'
            else:
                answer += 'N'
        elif key == 'C':
            if score[key] >= 0:
                answer += 'C'
            else:
                answer += 'F'
        elif key == 'J':
            if score[key] >= 0:
                answer += 'J'
            else:
                answer += 'M'
        elif key == 'R':
            if score[key] >= 0:
                answer += 'R'
            else:
                answer += 'T'
    return answer