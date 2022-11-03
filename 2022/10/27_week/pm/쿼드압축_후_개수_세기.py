def solution(arr):
    global answer
    answer = [0, 0]
    dfs(arr)
    return answer

def check(arr):
    chk = arr[0][0]
    for i in arr:
        for j in i:
            if j != chk:
                return False
    else:
        return True

def dfs(arr):
    if check(arr):
        answer[arr[0][0]] += 1
        return
    else:
        half = len(arr) // 2
        tmp1, tmp2 = [], []
        for i in range(half):
            tmp1.append(arr[i][:half])
            tmp2.append(arr[i][half:])
        dfs(tmp1)
        dfs(tmp2)
        tmp1, tmp2 = [], []
        for i in range(half, len(arr)):
            tmp1.append(arr[i][:half])
            tmp2.append(arr[i][half:])
        dfs(tmp1)
        dfs(tmp2)