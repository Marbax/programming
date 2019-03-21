#!/usr/bin/python
import sys
import math
#Rahuemo rivnyannya
x = float(sys.argv[1])
u = float(sys.argv[2])
o = float(sys.argv[3])
fr = 1 / (o * math.sqrt(2 * math.pi))
sc1 = 2 * o ** 2
sc2 = math.pow(x - u, 2)
sc = math.exp(-(sc2 / sc1))

f = fr * sc
print (f)
