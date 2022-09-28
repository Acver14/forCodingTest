def solution(users, emoticons):
    answer = [0, 0]

    discount = [10, 20, 30, 40]
    for d in discount:
        user_buy = [[0, False] for _ in range(len(users))]
        temp = [0, 0]
        for idx, val in enumerate(users):
            percent, maximum = val
            if d >= percent:
                for price in emoticons:
                    user_buy[idx][0] += price * (100-percent) // 100
                if user_buy[idx][0] >= maximum:
                    temp[1] += 1
                else:
                    temp[0] += user_buy[idx][0]
        print(d, answer, temp)
        if answer[1] <= temp[1]:
            answer = temp.copy()


    return answer