#!/usr/bin/python

import sys

x = int(sys.argv[1])
y = int(sys.argv[2])
z = int(sys.argv[3])

if (x and y and z >= 0) and ( x > 0 ) and ( z < 2 ) :
 text = y * (' la' +(x - 1) * ('-la')) + z * '!' + (1-z) * '.'
 song = "Everybody sing a song:"+text
 print (song)
else : print ("Wrong input")

