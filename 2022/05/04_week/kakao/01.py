# 문제설명
# 카카오 MBTI를 Return 해주는 Solution 함수를 제작하라. Solution의 매개함수는 아래 입 출력 예시와 같다.
# 입력 조건
# 1 ≤ survey의 길이 ( = n) ≤ 1,000
# survey의 원소는 "XY"로 나타내며, X는 첫번째 캐릭터, Y는 두번째 캐릭터로 칭한다.
# X, Y 는 각각 R, T, F, C, M, J, A, N 값이 들어갈 수 있습니다.

# survey[i]의 첫 번째 캐릭터는 i+1번 질문의 비동의 관련 선택지를 선택하면 받는 성격 유형을 의미합니다.
# survey[i]의 두 번째 캐릭터는 i+1번 질문의 동의 관련 선택지를 선택하면 받는 성격 유형을 의미합니다.
# choices의 길이 = survey의 길이

# choices[i]는 검사자가 선택한 i+1번째 질문의 선택지를 의미합니다.
# 1 ≤ choices의 원소 ≤ 7


# 입 출력 예시
# survey	                         choices         	result
# ["AN", "CF", "MJ", "RT", "NA"]	[5, 3, 2, 7, 5]	    "TCMA"
# ["TR", "RT", "TR"]               	[7, 1, 3]	        "RCJA"

survey = ["AN", "CF", "MJ", "RT", "NA"]
choices = [5, 3, 2, 7, 5]

ans = [0] * 4
for i in range(len(survey)):
    if survey[i][0] == 'T':
        ans[0] -= choices[i]
    elif survey[i][0] == 'R':
        ans[0] += choices[i]
    elif survey[i][0] == 'F':
        ans[1] -= choices[i]
    elif survey[i][0] == 'C':
        ans[1] += choices[i]
    elif survey[i][0] == 'M':
        ans[2] -= choices[i]
    elif survey[i][0] == 'J':
        ans[2] += choices[i]
    elif survey[i][0] == 'A':
        ans[3] -= choices[i]
    elif survey[i][0] == 'N': 
        ans[3] += choices[i]
        
mlist = [['R', 'T'], ['F', 'C'], ['M', 'J'], ['A', 'N']]
result = ''
print(ans)
for i in range(len(ans)):
    if ans[i] > 0:
        result += mlist[i][1]
    elif ans[i] < 0:
        result += mlist[i][0]
    else:
        if mlist[i][0] >= mlist[i][1]:
            result += mlist[i][1]
        else:
            result += mlist[i][0]
            
print(result)