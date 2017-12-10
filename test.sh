#!/bin/bash


red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
cian='\033[0;36m'
white='\e[0m'


cd stress_tests/

./main_tests.py $1 ../input $2

cd ..
./test_structures input output


cd stress_tests/
./read_tests.py ../output