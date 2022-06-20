def solution(s):
    answer = 1000
    n = len(s)//2 + 1
    if len(s) == 1:
        answer = 1
    for i in range(1, n):
        temp_str = s[:i]
        result = ''
        cnt = 1
        j = i
        while j < len(s):
            if temp_str == s[j:j+i]:
                cnt += 1
            else:
                if cnt > 1:
                    result += str(cnt) + temp_str
                    cnt = 1
                else:
                    result += temp_str
            if j+i > len(s):
                temp_str = s[j:]
            else:
                temp_str = s[j:j+i]
            j += i
        if cnt > 1:
            result += str(cnt) + temp_str
        else:
            result += temp_str
            
        answer = min(answer, len(result))
    return answer