import heapq

def solution(operations):
    answer = []
    q = []
    for operation in operations:
        oper, param = operation.split(' ')
        if oper == 'I':
            heapq.heappush(q, int(param))
        elif q:
                if param == '1':
                    q = heapq.nlargest(len(q), q)[1:]
                    heapq.heapify(q)
                else:
                    del q[0]
    if q:
        return [max(q), min(q)]
    else:
        return [0, 0]
    
