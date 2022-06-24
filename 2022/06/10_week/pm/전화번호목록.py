def solution(phone_book):
    phone_book.sort(key=len)
    phone_book.sort()
    
    # 접두어일 경우 False, 아닐 경우 True
    for i in range(len(phone_book)-1):
        l = len(phone_book[i])
        if phone_book[i] == phone_book[i+1][:l]:
            return False
    return True