def solution(k, ranges):
    answer = []
    seq = [k]
    while k != 1:
        if k % 2 == 0:
            k //= 2
        else:
            k = k*3+1
        seq.append(k)
    area = []
    prev = seq[0]
    for i in range(1, len(seq)):
        area.append((prev+seq[i])/2)
        prev = seq[i]
    for s, e in ranges:
        e += len(seq)-1
        if s > e:
            answer.append(-1.0)
        elif s == e:
            answer.append(0.0)
        else:
            answer.append(sum(area[s:e]))
    return answer