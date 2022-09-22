from collections import defaultdict

def solution(id_list, report, k):
    answer = []
    report_dict = defaultdict(set)
    ans_dict = defaultdict(int)
    for r in report:
        _from, _to = r.split()
        report_dict[_to].add(_from)
        
    for key, val in report_dict.items():
        if len(val) >= k:
            for x in val:
                ans_dict[x] += 1
                
    for i in id_list:
        answer.append(ans_dict[i])
    
    return answer