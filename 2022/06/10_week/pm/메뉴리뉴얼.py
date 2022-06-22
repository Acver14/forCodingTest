from collections import defaultdict
from itertools import combinations
def solution(orders, course):
    answer = []
    d = defaultdict(set)
    for i in range(len(orders)):
        for j in orders[i]:
            d[i].add(j)

    res = defaultdict(int)
    for i in range(1, len(d)):
        for j in range(i):
            temp = list(d[i] & d[j])
            sorted(temp)
            parts = []
            if len(temp) > 1:
                for k in range(2, len(temp)+2):
                    parts += list(combinations(temp, k))
                for p in parts:
                    p = list(p)
                    p.sort()
                    res[''.join(p)] += 1
    
    level = [0 for _ in range(11)]
    for i in res.keys():
        if len(i) in course and level[len(i)] < res[i]:
            level[len(i)] = res[i]
            
    for i in res.keys():
        if res[i] >= level[len(i)] > 0:
            temp = list(i)
            temp.sort()
            answer.append(''.join(temp))
    answer.sort()
    return answer

# import collections
# import itertools

# def solution(orders, course):
#     result = []

#     for course_size in course:
#         order_combinations = []
#         for order in orders:
#             order_combinations += itertools.combinations(sorted(order), course_size)

#         most_ordered = collections.Counter(order_combinations).most_common()
#         result += [ k for k, v in most_ordered if v > 1 and v == most_ordered[0][1] ]

#     return [ ''.join(v) for v in sorted(result) ]
