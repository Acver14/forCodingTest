from itertools import permutations
import re

def cal(a, b, oper):
    a, b = int(a), int(b)
    if oper == '+':
        return str(a+b)
    elif oper == '-':
        return str(a-b)
    elif oper == '*':
        return str(a*b)

def solution(expression):
    answer = 0
    operator = ['+', '-', '*']
    for idx, oper in enumerate(operator):
        if oper not in expression:
            operator.pop(idx)
    operator = permutations(operator)

    for oper in operator:
        express = re.split(r'(\D)',expression)
        for op in oper: 
            while True:
                try:
                    idx = express.index(op)
                    express[idx-1] = cal(express[idx-1], express[idx+1], express[idx])
                    express.pop(idx)
                    express.pop(idx)
                except:
                    break
        answer = max(answer, abs(int(express[0])))
    return answer

# def solution(expression):
#     operations = [('+', '-', '*'),('+', '*', '-'),('-', '+', '*'),('-', '*', '+'),('*', '+', '-'),('*', '-', '+')]
#     answer = []
#     for op in operations:
#         a = op[0]
#         b = op[1]
#         temp_list = []
#         for e in expression.split(a):
#             temp = [f"({i})" for i in e.split(b)]
#             temp_list.append(f'({b.join(temp)})')
#         answer.append(abs(eval(a.join(temp_list))))
#     return max(answer)