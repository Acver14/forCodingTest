import requests
import json

BASE_URL = 'https://kox947ka1a.execute-api.ap-northeast-2.amazonaws.com/prod/users'
X_AUTH_TOKEN = '539470bf0c435423d8c91d55cfb5e2da'

total_score = 0.0
missed = [0, 0, 0]
checked = [0, 0, 0]
for k in range(1,3):
    # Start API
    # 문제를 풀기 위한 key를 발급한다. Start API를 실행하면 파라미터로 전달한 문제 번호에 맞게 각 자전거 대여소 및 트럭에 대한 정보를 초기화한다.
    headers = {'Content-Type': 'application/json; chearset=utf-8', 'X-Auth-Token': X_AUTH_TOKEN}
    data = {'problem': k}
    res = requests.post(BASE_URL + '/start', data=json.dumps(data), headers=headers)
    auth_key = res.json()['auth_key']
    while True:
        try:
            # Locations API
            # 현재 카카오 T 바이크 서비스 시각에 각 자전거 대여소가 보유한 자전거 수를 반환한다.
            headers = {'Content-Type': 'application/json', 'Authorization': auth_key}
            res = requests.get(BASE_URL + '/locations', headers=headers)
            # print(str(res.status_code) + " | " + res.text)

            # Trucks API
            # 현재 카카오 T 바이크 서비스 시각에 각 트럭의 위치와 싣고 있는 자전거 수를 반환한다.
            res = requests.get(BASE_URL + '/trucks', headers=headers)
            trucks = res.json()['trucks']

            # Simulate API
            # 현재 시각 ~ 현재 시각 + 1분 까지 각 트럭이 행할 명령을 담아 서버에 전달한다. 호출 시 서버에서는 다음과 같은 일이 진행된다.

            data = {
                'commands' :[]
            }
            for i in trucks:
                data['commands'].append({
                    "truck_id": i['id'],
                    "command": []
                })
            res = requests.put(BASE_URL + '/simulate', data=json.dumps(data), headers=headers)
            missed[k] = int(float(res.json()['failed_requests_count']))
            if res.json()['time'] % 100 == 0:
                print(res.json()['time'])
            if res.json()['status'] == 'finished':
                # Score API
                # 해당 Auth key로 획득한 점수를 반환한다. 점수는 높을수록 좋다. 카카오 T 바이크 서버의 상태가 finished가 아닐 때 본 API를 호출하면 response의 score는 무조건 0.0이다.
                headers = {'Content-Type': 'application/json', 'Authorization': auth_key}
                res = requests.get(BASE_URL + '/score', headers=headers)
                print(str(res.status_code) + " | " + res.text)
                total_score += res.json()['score']
                break
        except Exception as e:
            print(e)

print(total_score, missed)