all:
	g++ -ggdb -o program  cchash.cpp heap.cpp main.cpp -std=c++11
clean: 
	$(RM) program
