from sys import stdin
from collections import defaultdict
import datetime
input = stdin.readline

n, l, f = input().rstrip().split()

standard = datetime.timedelta(days=int(l.split('/')[0]), hours=int(l.split('/')[1].split(':')[0]), minutes=int(l.split('/')[1].split(':')[1]))
paper = defaultdict(lambda: datetime.datetime.min)
bill = defaultdict(int)
for _ in range(int(n)):
    temp = input().rstrip().split()
    title = temp[2]+' '+temp[3]
    name = temp[3]
    time = datetime.datetime.strptime(temp[0]+' '+temp[1], '%Y-%m-%d %H:%M')
    if paper[title] != datetime.datetime.min:
        gab = (time - paper[title])
        if gab > standard:
            gab -= standard
            bill[name] += gab.total_seconds()/60*int(f)
        paper[title] = datetime.datetime.min
    else:    
        paper[title] = time
        
if bill:
    bill = sorted(bill.items())
    for key, value in bill:
        print(key, round(value))
else:
    print(-1)