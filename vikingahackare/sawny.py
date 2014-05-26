from sys import stdin;

# Varz
decrypted    = [];

# Input
data 		 = stdin.read().split();
alphabetLen  = int(data.pop(0));
encrypted    = data.pop(len(data)-1);
alphabet     = data;
alphabet     = dict(zip(alphabet[1::2], alphabet[0::2])); # {from : to, ...}

encrypted = [encrypted[i:i+4] for i in range(0, len(encrypted), 4)]; # I start to like you python. (but still, why no str_split($str, 4)? >.>)


for chr in encrypted:
	decrypted.append(alphabet[chr] if chr in alphabet else '?');


print ''.join(decrypted);