from sys import stdin

data = stdin.read().split();
p    = float(data.pop());
k    = int(data.pop());
n    = int(data.pop());

print "Spela inte!" if n*p >= k else "Spela";