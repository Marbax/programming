#!/usr/bin/python

import sys

n1 = int(sys.argv[1])
n2 = int(sys.argv[2])
res = 0
num = []

#if ((n1 , n2 >= 0) and (n1 <= n2) and (n1 , n2 <= 999999)) :
#if (((n1 and n2) >= 0) and (n1 <= n2) and ((n1 and n2) <= 999999)) : #not working
if ((n1 >= 0) and (n2 >= 0) and (n1 <= n2) and (n1 <= 999999) and (n2 <= 999999)) :
    while (int(n1) <= int(n2)) :
        num = []
        for i in str(n1) :
            num.append(i)
        while ((len(num) < 6) or (len(num) == 0)) :
            num.insert(0,0)
        if (int(num[0]) + int(num[1]) + int(num[2]) == (int(num[3]) + int(num[4]) + int(num[5]))) :
            res = res + 1
        n1 = n1 + 1
print res
