CXXFLAGS+=-std=c++11 -Wall

prog: main.cpp legacy_database.cpp legacy_database.h database.cpp database.h
	g++ main.cpp legacy_database.cpp database.cpp -o prog

clean:
	rm -f prog
