#!/bin/bash


 
cd stress_tests/

./$2 $1 ../input

cd ..
./test_structures_update input output

cd stress_tests/

./read_specified_tests.py ../output



