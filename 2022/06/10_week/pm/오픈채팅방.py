from collections import defaultdict
def solution(record):
    answer = []
    log = defaultdict(str)
    chats = []
    for i in range(len(record)):
        line = record[i].split()
        if line[0] == 'Enter':
            log[line[1]] = line[2]
            chats.append(line[1] + '님이 들어왔습니다.')
        elif line[0] == 'Leave':
            chats.append(line[1] + '님이 나갔습니다.')
        elif line[0] == 'Change':
            log[line[1]] = line[2]
    for i in range(len(chats)):
        name, chat = chats[i].split('님')
        answer.append(log[name] + '님' + chat)
        
    return answer