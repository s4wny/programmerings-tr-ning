import argparse
from random import randint

parser = argparse.ArgumentParser(description='generate-data.py -n 1337 -t 9999 > limousinen.5.in')
parser.add_argument('-n', '--n',    help='Number of cordinates (max 100000)', type=int, required=True)
parser.add_argument('-t', '--time', help='Max time (max 10^9)',               type=int, required=True)
args = vars(parser.parse_args())

print str(args['n']) +" "+ str(args['time'])

for x in xrange(0, args['n']):
    print str(randint(-pow(10, 6), pow(10,6))) +" "+ str(randint(-pow(10, 6), pow(10,6)))