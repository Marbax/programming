#!/usr/bin/python

import sys

text = sys.argv[1]
j = "()"

if ((text[0] == '(') and (text[-1] == ')') and text.count('(')==text.count(')')) :
    for i in text :
        text = text.replace(j,"")
    if len(text) == 0 :
        print ("YES")

else :
    print ("NO")
