#2021.07.20
for i in range(100):
    try:
        _str = input()
        print(_str)
    except EOFError():
        break