n = int(input())

a,b,c = map(int,input().split())

_max = [a,b,c]
_min = [a,b,c]

for i in range(n-1):
    one,two,thr = map(int,input().split())
    max_0 = one + max(_max[0],_max[1])
    min_0 = one + min(_min[0],_min[1])
    max_1 = two + max(_max[0],_max[1],_max[2])
    min_1 = two + min(_min[0],_min[1],_min[2])
    max_2 = thr + max(_max[1],_max[2])
    min_2 = thr + min(_min[1],_min[2])
    _max = [max_0,max_1,max_2]
    _min = [min_0,min_1,min_2]

    
print(max(_max), min(_min))
