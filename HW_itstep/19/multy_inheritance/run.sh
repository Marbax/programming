#!/bin/bash
find *.cpp ./ | grep cpp | grep ./ > ./tmp
g++ @tmp Point.h -o project.out && ./project.out
rm -f ./project.out ./tmp
