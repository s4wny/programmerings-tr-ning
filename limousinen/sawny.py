from sys import stdin
import operator

data       = stdin.read().split();
data       = map(int, data);
n          = data.pop(0);
t          = data.pop(0);
counter    = 0;
summedTime = 0;

distance = map(operator.add, map(abs, data[0::2]), map(abs, data[1::2])); # Speed is important
distance.sort();

length = len(distance); 

summedTime = distance[0]*2;

while t-summedTime >= 0:
    counter += 1;

    if(length-counter == 0): # micro optimization
        break;
    else:
        summedTime += distance[counter]*2; # Speed is vital, dont use distance.pop(0). MUCH MUCH faster to just GET() from a list. pop(0) will modify the list, takes too much time!

print counter;