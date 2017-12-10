compiler    := g++
std_version := -std=c++14


RED='\033[0;31m'         #  ${RED}
GREEN='\033[0;32m'      #  ${GREEN}
WHITE='\e[0m'



array_tests:
	$(compiler) $(flags) structures.cpp -o structures.test.out
	./structures.test.out


clear:
	rm *.o *.test.out *.out
