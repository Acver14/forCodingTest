def solution(s):
    answer = []
    expression = ''.join(s.split('{')).split('}')
    arr = []
    for express in expression:
        arr.append([])
        for ex in express.split(','):
            if ex:
                arr[-1].append(int(ex))
        if not arr[-1]: arr.pop()
    arr.sort(key=len)

    answer.append(arr[0][0])
    for i in range(1, len(arr)):
        for ans in answer:
            arr[i].remove(ans)
        answer.append(arr[i][0])
    return answer

# def solution(s):
#     answer = []

#     s1 = s.lstrip('{').rstrip('}').split('},{')

#     new_s = []
#     for i in s1:
#         new_s.append(i.split(','))

#     new_s.sort(key = len)

#     for i in new_s:
#         for j in range(len(i)):
#             if int(i[j]) not in answer:
#                 answer.append(int(i[j]))

#     return answer