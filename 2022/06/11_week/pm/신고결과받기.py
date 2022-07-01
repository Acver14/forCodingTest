from collections import defaultdict

def solution(id_list, report, k):
    answer = [0] * len(id_list)
    report_vec = defaultdict(set)
    reported = defaultdict(int)
    for r in report:
        a, b = r.split()
        if not a in report_vec[b]:
            reported[b] += 1
            report_vec[b].add(a)
    for _id in id_list:
        if reported[_id] >= k:
            for r in report_vec[_id]:
                answer[id_list.index(r)] += 1
    return answer