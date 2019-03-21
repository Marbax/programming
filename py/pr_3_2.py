#!/usr/bin/python

import sys

a = 0
b = 1

n = int(sys.argv[1])

for i in range(n) :
    a, b = b, a + b
print a
