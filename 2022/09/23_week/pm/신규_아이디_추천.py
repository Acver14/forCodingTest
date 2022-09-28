def solution(new_id):
    answer = ''
    #1
    new_id = new_id.lower()
    #2
    new_id = [i for i in new_id if i.isalnum() or i=='.' or i=='-' or i=='_']
    #3
    prev = ''
    for i, v in enumerate(new_id):
        if prev == '.' and v == '.':
            new_id[i] = ''
        else:
            prev = v
    #4
    new_id = ''.join(new_id).strip('.')
    #5
    if new_id == '':
        new_id = 'a'
    #6
    if len(new_id) > 15:
        new_id = new_id[:15]
        new_id = new_id.rstrip('.')
    #7
    while len(new_id) < 3:
        new_id += new_id[-1]

    return new_id
