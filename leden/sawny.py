from sys import stdin
 
data      = stdin.read().split()
length    = data.pop(0);
wayPoints = map(int, data);
time      = 0;
 
for i, wayPoint in enumerate(wayPoints[0:-1]):
    time  = time + abs(-5 - -1*(wayPoint-wayPoints[i+1]))*2 + 60;    
 
print time;