from sys import stdin

# -20 meter = 90s     +30s
# -5  meter = 60s     +0s
# 0   meter = 70s     +10s
# 10  meter = 90s     +20s

data      = stdin.read().split()
length    = data.pop(0);
wayPoints = map(int, data);

time      = 0;
stdSlope  = -5;
baseTime  = 60;

for i, wayPoint in enumerate(wayPoints[0:-1]):
    slope = -1*(wayPoint-wayPoints[i+1]);
    time  = time + abs(stdSlope - slope)*2 + baseTime;    

print time;