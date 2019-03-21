#!/usr/bin/python

import sys

ryadok_2 = []
ryadok = sys.argv[1:]

for element in ryadok[::-1] :
    ryadok_2.append(element)

ryadok_2 = ' '.join(ryadok_2)

print ryadok_2
