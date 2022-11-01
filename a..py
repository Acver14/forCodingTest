data = [(170, 60, 4.1),(165, 55, 3.0),(174, 75, 2.8),(169, 67, 2.9),(155, 49, 3.1),(172, 63, 3.6),(166, 58, 3.7),(168, 61, 4.0)]

N = len(data)
    
_sum = [0, 0, 0]
for h, w, g in data:
    _sum[0] += h
    _sum[1] += w
    _sum[2] += g
else:
    print(_sum[0] / N, _sum[1] / N, _sum[2] / N)
print()

avg = [0, 0, 0]
for i in range(len(_sum)):
    avg[i] = _sum[i]/N
    
cov = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
for h, w, g in data:
    cov[0][0] += (h-avg[0])*(h-avg[0])
    cov[0][1] += (h-avg[0])*(w-avg[1])
    cov[0][2] += (h-avg[0])*(g-avg[2])
    
    cov[1][0] += (w-avg[1])*(h-avg[0])
    cov[1][1] += (w-avg[1])*(w-avg[1])
    cov[1][2] += (w-avg[1])*(g-avg[2])
    
    cov[2][0] += (g-avg[2])*(h-avg[0])
    cov[2][1] += (g-avg[2])*(w-avg[1])
    cov[2][2] += (g-avg[2])*(g-avg[2])

else:
    print(cov[0][0] / N, cov[0][1] / N, cov[0][2] / N)
    print(cov[1][0] / N, cov[1][1] / N, cov[1][2] / N)
    print(cov[2][0] / N, cov[2][1] / N, cov[2][2] / N)