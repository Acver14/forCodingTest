# def solution(name):
#     if set(name) == {'A'}:
#         return 0

#     answer = float('inf')
#     for i in range(len(name) // 2): # 반 이상 움직일 필요 없음
#         left_moved = name[-i:]+name[:-i]
#         right_moved = name[i:]+name[:i]
#         for n in [left_moved, right_moved[0]+right_moved[:0:-1]]:
#             while n and n[-1] == 'A':
#                 n = n[:-1]

#             row_move = i + len(n)-1
#             col_move = 0
#             for c in map(ord, n):
#                 col_move += min(c - 65, 91 - c)

#             answer = min(answer, row_move + col_move)

#     return answer

def solution(name):
    answer = 0
    s = ['A']*len(name)
    name = list(name)
    rans, lans = 0, 0
    for idx, val in enumerate(name):
        if ''.join(name[:idx+1]) == ''.join(['A']*(idx+1)):
            break
        if 'A' != val:
            rans += min(abs(ord(val) - ord('A')), abs(ord(val) - ord('Z'))+1)
        rans+=1
        
    name.append(name.pop(0))
    for idx, val in reversed(list(enumerate(name))):
        if ''.join(name[:idx+1]) == ''.join(['A']*(idx+1)):
            break
        if 'A' != val:
            lans += min(abs(ord(val) - ord('A')), abs(ord(val) - ord('Z'))+1)
        lans+=1
    answer = min(rans, lans)-1
    return answer