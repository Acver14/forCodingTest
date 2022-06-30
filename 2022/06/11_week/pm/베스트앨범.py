from collections import defaultdict

def solution(genres, plays):
    answer = []
    total_play = defaultdict(int)
    play_list = defaultdict(list)
    for idx, val in enumerate(genres):
        total_play[val] += plays[idx]
    rank = []
    idx = 0
    for k, v in total_play.items():
        rank.append([k, v])
        idx+=1
    rank.sort(key=lambda x:x[1], reverse=True)
    
    for idx, val in enumerate(plays):
        play_list[genres[idx]].append([idx, val])
    for p in play_list.values():
        p.sort(key=lambda x:x[1], reverse=True)
    
    for r in rank:
        for i in range(2):
            try:
                answer.append(play_list[r[0]][i][0])
            except:
                break
    
    return answer