# 단체 손님이 많이 방문하는 예약제 호텔이 있습니다. 
# 호텔에 머무는 단체 손님들은 인원수만큼의 인접한 객실을 배정받기를 원합니다.
# 당신은 최대한 많은 손님이 방을 배정받을 수 있도록 예약을 관리해, 호텔의 객실 이용률을 목표치 이상으로 만들어야 합니다.

# 목표 : 호텔의 객실 이용률이 목표치 이상이 되도록 예약을 관리하거나 객실을 배정하면서, 객실 수가 많은 예약은 최대한 거절하지 않아야 합니다.

# 각 객실 번호는 "ABBB" 혹은 "AABBB" 형태이며, A는 객실의 층, B는 객실

# 모든 객실의 체크아웃 시각은 오전 11시, 체크인 시각은 오후 2시입니다
# 즉, 어떤 객실에서 체크아웃이 발생한 날짜에 바로 체크인이 가능합니다.

# 예약 요청은 다음 정보를 포함하고 있습니다.
# 요청 id / 객실 수 / 체크인 날짜 / 체크아웃 날짜
# 요청 id는 고유한 6자리 정수입니다.
# 체크인 날짜는 예약 요청이 들어온 날짜로부터 최소 1일 뒤, 최대 21일 뒤입니다.

# 각 예약 요청의 답변 기한까지 예약을 승낙할지 거절할지 정해 답변해야 합니다.
# 예약 요청의 답변 기한 = min(예약 요청이 들어온 날짜 + 14 , 체크인 날짜 - 1)
# 기한까지 답변을 하지 않은 예약은 거절한 것으로 처리됩니다.

# 승낙한 예약 요청의 체크인 날짜가 되면 손님이 호텔에 도착합니다.
# 도착한 손님이 예약한 객실 수만큼의 비어있는 객실을 배정해야 합니다. 이때 객실들은 같은 층에서 인접한 연속된 객실이어야 합니다.
from email.policy import default
import traceback
from urllib import request
import requests
import json
import time
from collections import defaultdict
BASE_URL = 'https://68ecj67379.execute-api.ap-northeast-2.amazonaws.com/api'

def start(problem = 1):
    global BASE_URL
    headers = {'Content-Type': 'application/json; chearset=utf-8', 'X-Auth-Token': 'daa5b85d48103de6653d75e5b9a476ff'}
    data = {'problem': problem}
    res = requests.post(BASE_URL + '/start', data=json.dumps(data), headers=headers)
    return res.json()['auth_key'], res.json()['day']
def newRequest(auth_key):
    headers = {'Content-Type': 'application/json', 'Authorization': auth_key}
    return requests.get(BASE_URL + '/new_requests', headers=headers).json()
def reply(auth_key, data):
    global BASE_URL
    # "replies": [
    #        { "id": 412424, "reply": "accepted"},
    #        { "id": 707981, "reply": "refused"},
    #        ...
    #      ]
    data = {
        'replies' : data
    }
    headers = {'Content-Type': 'application/json', 'Authorization': auth_key}
    return requests.put(BASE_URL + '/reply', data=json.dumps(data), headers=headers).json()
def simulate(auth_key, data):
    global BASE_URL
    data = {
        'room_assign' : data
    }
    headers = {'Content-Type': 'application/json', 'Authorization': auth_key}
    return requests.put(BASE_URL + '/simulate', data=json.dumps(data), headers=headers).json()
def score(auth_key):
    headers = {'Content-Type': 'application/json', 'Authorization': auth_key}
    return requests.get(BASE_URL + '/score', headers=headers).json()
    
def possilbeReservation(amount, check_in_date, check_out_date, problem):
    global used_room
    H, W = 4, 21
    if problem == 2:
        H, W = 10, 201
    for h in range(1, H):
        cnt = 0
        flag = False
        for w in range(1, W-amount+1):
            for s in range(amount):
                if flag:
                    break
                for i in range(check_in_date, check_out_date):
                    room_number = str(h) + str(w+s).zfill(3)
                    if room_number in used_room[i]:
                        flag = True
                        break
                    else:
                        cnt += 1
                    if cnt == amount * (check_out_date-check_in_date):
                        return h, w
    return 0

    

def printArr(arr):
    for a in arr:
        print(a)
def printDictArr(dictarr):
    for i, v in dictarr.items():
        print(i, v)

def problem(problem = 1):
    global used_room
    auth_key, D = start(problem)
    reservation_check = defaultdict(list)
    used_room = defaultdict(set)
    
    waiting_list = defaultdict(list)
    canceled_room = 0
    accepted_room = 0
    
    max_days = 200
    if problem == 2:
        max_days = 1000
    while D <= max_days:
        try:
            print(D)
            reservation_info = newRequest(auth_key)['reservations_info']
            for reserv in reservation_info:
                # min(예약 요청이 들어온 날짜 + 14 , 체크인 날짜 - 1)
                idx = max(1, min(D+14, reserv['check_in_date']-1))
                waiting_list[idx].append(reserv)
            waiting_list[D].sort(key = lambda x:x['check_out_date'])
            replies = []
            for reserv in waiting_list[D]:
                # reserv - "id": 453217, "amount": 10, "check_in_date": 104, "check_out_date": 110}
                room_number = possilbeReservation(reserv['amount'], reserv['check_in_date'], reserv['check_out_date'], problem)
                if room_number == 0:
                    replies.append({"id": reserv['id'], "reply": "refused"})
                    canceled_room += reserv['amount']
                else:
                    accepted_room += reserv['amount']
                    replies.append({"id": reserv['id'], "reply": "accepted"})
                    for d in range(reserv['check_in_date'], reserv['check_out_date']):
                        for a in range(reserv['amount']):
                            used_room[d].add(str(room_number[0]) + str(room_number[1]+a).zfill(3))
                        
                    reservation_check[reserv['check_in_date']].append({'id': reserv['id'], 'room_number':  str(room_number[0]) + str(room_number[1]).zfill(3)})
                    # waiting_list[D].remove(reserv)
            D = reply(auth_key, replies)['day']
            if D > max_days:
                break
            result = simulate(auth_key, reservation_check[D])
            D = result['day']
        except:
            continue
        
    print()
    print('score : ', score(auth_key))

if __name__ == "__main__":
    problem(1)
    problem(2)