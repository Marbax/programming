#!/usr/bin/python

import sys

pal = []
pal = sys.argv[1].lower()
pal = pal.replace(" ", "")
pal_rev = []
pal_norm = []

for letter in pal[::-1] :
    pal_rev.append(letter)
for letter in pal :
    pal_norm.append(letter)

if (pal_norm == pal_rev) :
    print("YES")
else :
    print("NO")
