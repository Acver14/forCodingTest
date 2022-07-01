from collections import defaultdict
import math
def solution(fees, records):
    answer = []
    logs = {}
    car_datas = defaultdict(int)
    for r in records:
        times, num, com = r.split()
        h, m = times.split(":")
        if com == 'IN':
            logs[num] = int(h)*60 + int(m)
        elif com == 'OUT':
            car_datas[num] += int(h)*60 + int(m) - logs[num]
            del logs[num]
            
    for l in logs.keys():
        car_datas[l] += 23*60 + 59 - logs[l]
    car_datas = [i[1] for i in sorted(car_datas.items())]
    min_time, min_fee, add_time, add_fee = fees
    for car in car_datas:
        result = min_fee
        remain_time = car-min_time
        if remain_time > 0:
            result += math.ceil(remain_time/add_time) * add_fee
        answer.append(result)
    return answer