from collections import defaultdict
def solution(str1, str2):
    answer = 0
    if len(str1) > len(str2):
        str1, str2 = str2, str1
        
    d1, d2 = defaultdict(int), defaultdict(int)
    for i in range(len(str1)):
        if str1[i:i+2].isalpha() and len(str1[i:i+2]) == 2:
            d1[str1[i:i+2].upper()] += 1
    for i in range(len(str2)):
        if str2[i:i+2].isalpha() and len(str2[i:i+2]) == 2:
            d2[str2[i:i+2].upper()] += 1
    
    x, y = defaultdict(int), defaultdict(int)
    for i in d1.keys():
        x[i] = max(d1[i], d2[i])
        if d2[i] == 0: continue
        y[i] = min(d1[i], d2[i])
    for i in d2.keys():
        x[i] = max(d1[i], d2[i])
    cnt1, cnt2 = sum(x.values()), sum(y.values())
    if x:
        answer = int(cnt2/cnt1 * 65536)
    elif x == y:
        answer = 65536
    return answer