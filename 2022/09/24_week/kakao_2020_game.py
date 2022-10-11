import traceback
import requests
import json
import time

def match(auth_key, data):
    global BASE_URL
    headers = {'Content-Type': 'application/json', 'Authorization': auth_key}
    return requests.put(BASE_URL + '/match', data=json.dumps(data), headers=headers).json()
def getGameResult(auth_key):
    global BASE_URL
    headers = {'Content-Type': 'application/json', 'Authorization': auth_key}
    return requests.get(BASE_URL + '/game_result', headers=headers).json()
def getWaitingList(auth_key):
    global BASE_URL
    headers = {'Content-Type': 'application/json', 'Authorization': auth_key}
    return requests.get(BASE_URL + '/waiting_line', headers=headers).json()
def getUserInfo(auth_key):
    global BASE_URL
    headers = {'Content-Type': 'application/json', 'Authorization': auth_key}
    return requests.get(BASE_URL + '/user_info', headers=headers).json()
def start(problem):
    global BASE_URL
    headers = {'Content-Type': 'application/json; chearset=utf-8', 'X-Auth-Token': '654fe8dd5df5e8f3cd70ad5c3f402652'}
    data = {'problem': problem}
    res = requests.post(BASE_URL + '/start', data=json.dumps(data), headers=headers)
    return res.json()['auth_key']
def changeGrade(auth_key, data):
    global BASE_URL
    data = {
        'commands' : data
    }
    headers = {'Content-Type': 'application/json', 'Authorization': auth_key}
    res = requests.put(BASE_URL + '/change_grade', data=json.dumps(data), headers=headers)
    

BASE_URL = 'https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod'
score = [{}, {}, {}]

for k in range(1, 3):
    auth_key = start(k)

    user_info = getUserInfo(auth_key)['user_info']
    user = {}
    for u in user_info:
        user[u['id']] = 5000
    T = match(auth_key, {'pairs': []})['time']
    matched = set([])
    result = []
    while True:
        try:
            waiting_line = getWaitingList(auth_key)['waiting_line']
            player_list = []
            for idx, que in enumerate(waiting_line):
                if que['id'] not in matched:
                    if que['from'] + 39 == T:
                        min_id, min_gab = float("inf"), float("inf")
                        for q in range(idx+1, len(waiting_line)):
                            if waiting_line[q]['id'] not in matched:
                                if user[que['id']] - user[waiting_line[q]['id']] < min_gab:
                                    min_id = user[waiting_line[q]['id']]
                                    min_gab = user[que['id']] - user[waiting_line[q]['id']]
                            player_list.append([que['id'], min_id])
                            matched.add(que['id'])
                            matched.add(min_id)
                            break
                    for q in range(idx+1, len(waiting_line)):
                        if waiting_line[q]['id'] not in matched:
                            if user[que['id']] - 10 <= user[waiting_line[q]['id']] <= user[que['id']] + 10:
                                player_list.append([que['id'], waiting_line[q]['id']])
                                matched.add(que['id'])
                                matched.add(waiting_line[q]['id'])
                                break
            print('set', matched, T)
            print(player_list)
            print()
            match_result = match(auth_key, {'pairs': player_list})
            T = match_result['time']
            
            if match_result['status'] == 'finished':
                break
                
            gameResult = getGameResult(auth_key)
            if gameResult['game_result']:
                result.append(gameResult)
                for win in gameResult['game_result']:
                    user[win['win']] += 40 - win['taken']
                    user[win['lose']] -= 40 - win['taken']
                    matched.discard(win['win'])
                    matched.discard(win['lose'])
                    print('result', user[win['win']], user[win['lose']])
            
            if T == 595:
                data = []
                for i, v in user.items():
                    data.append({
                        'id' : i,
                        'grade': v
                    })
                changeGrade(auth_key, data)
            
        except Exception as e:
            traceback.print_exc()
            time.sleep(1)
            continue
    
    
    # UserInfo API
    # 모든 유저들의 현재 등급을 반환한다.
    user_log = getUserInfo(auth_key)
    print(user_log)
    
    
    headers = {'Content-Type': 'application/json', 'Authorization': auth_key}
    res = requests.get(BASE_URL + '/score', headers=headers)
    
    score[k] = res.json()
    
for s in score:
    print(s)