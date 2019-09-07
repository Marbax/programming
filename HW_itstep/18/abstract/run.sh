#!/bin/bash
find *.cpp ./ | grep cpp | grep ./ > ./tmp
g++ @tmp -o project.out && ./project.out
rm -f ./project.out ./tmp
