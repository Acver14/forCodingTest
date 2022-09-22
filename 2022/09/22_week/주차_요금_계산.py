from collections import defaultdict

def solution(fees, records):
    answer = []
    inout_dict = defaultdict(int)
    record_dict = defaultdict(int)
    for record in records:
        time, car, oper = record.split()
        if oper == 'IN':
            temp = time.split(':')
            inout_dict[car] = int(temp[0]) * 60 + int(temp[1])
        else:
            temp = time.split(':')
            record_dict[car] += (int(temp[0])*60+int(temp[1])) - inout_dict[car]
            inout_dict[car] = -1
    for i, v in inout_dict.items():
        if v != -1:
            record_dict[i] += 24*60-1 - v
    for k in sorted(record_dict.keys()):
        fee = fees[1]
        record_dict[k] -= fees[0]
        if record_dict[k] > 0:
            fee += (record_dict[k])//fees[2] * fees[3]
            if record_dict[k] % fees[2] != 0:
                fee += fees[3]
        answer.append(fee)
    return answer