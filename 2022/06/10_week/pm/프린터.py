def solution(priorities, location):
    answer = 0
    cnt = 0
    while priorities:
        p = priorities.pop(0)
        if priorities and max(priorities) > p:
            priorities.append(p)
            if location == 0:
                location = len(priorities)-1
            else:
                location -= 1
        else:
            cnt += 1
            if location == 0:
                return cnt
            else:
                location -= 1
    return cnt