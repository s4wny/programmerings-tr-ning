from sys import stdin

data = stdin.read().split();
data = map(int, data);
sum  = 0;

for s in data[::2]:
	sum = sum + 3*s;

for s in data[1::2]:
	sum = sum + 7*s;

print sum % 10