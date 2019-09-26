#!/bin/bash
g++ main.cpp -o caesar.exe && echo "" && echo  "                  CAESAR BUILD IT FOR U! AVE CAESAR!"
echo ""
echo " AND EXAMPLES HOW TO RUN THAT :"
echo "./caesar.exe --crypt path_to_source path_to_out path_where_create_key"
echo " OR "
echo " ./caesar.exe --decrypt path_to_crypted_file path_to_key "
echo " "