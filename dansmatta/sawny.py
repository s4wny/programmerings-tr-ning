from sys import stdin


def bestFootToMove(footA, footB, beats):
	for step in beats:
		if len(step) == 2:
			# Both steps are correct, keep searching further
			if (footA == step[0] and footB == step[1]) or (footA == step[1] and footB == step[0]):
				pass
			else:
				if footA == step[0] or footA == step[1]:
					return 'B';
				if footB == step[0] or footB == step[1]:
					return 'A';
		else:
			if footA == step:
				return 'B';
			if footB == step:
				return 'A';

	return 0;

# Data
data   = stdin.read().split();
nBeats = data.pop(0);
beats  = data;

# Varz
footA  = 'V';
footB  = 'H';
moves = 0;


for i, step in enumerate(beats):
	step = list(step);

	if len(step) == 1:
		# Both correct?
		if step[0] == footA or step[0] == footB:
			pass
		# One wrong
		else:
			if bestFootToMove(footA, footB, beats[i::]) == 'A':
				footA = step[0];
			else:
				footB = step[0];

			moves += 1;
	else:
		# Already correct position?
		if (footA == step[0] and footB == step[1]) or (footA == step[1] and footB == step[0]):
			pass

		# One correct?
		elif (footA == step[0] and footB != step[1]) or (footA == step[1] and footB != [0]) or (footB == step[0] and footA != step[1]) or (footB == step[1] and footA != [0]):
			# A correct. Move B
			if footA == step[0] or footA == step[1]:
				footB = step[1] if footA == step[0] else step[0];
				moves += 1;

			# B correct. Move A
			elif footB == step[0] or footB == step[1]:
				footA = step[1] if footB == step[0] else step[0];
				moves += 1;

		# Both wrong?
		else:
			footA = step[0];
			footB = step[1];

			moves += 2;

				
print moves;