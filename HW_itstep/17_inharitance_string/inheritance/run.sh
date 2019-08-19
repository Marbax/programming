#!/bin/bash
clear
g++ main.cpp DATE.h FIO.h Pasport.h ForeignPasport.h && ./a.out
rm -rf *.out *.gch
