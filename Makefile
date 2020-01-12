CXXFLAGS=-Wall -Wextra
OBJECTS=main.o dictionary.o lexer.o argumentparser.o

all: $(OBJECTS)
	g++ $(CXXFLAGS) $(OBJECTS) -o exec

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp

dictionary.o: translation/dictionary.cpp translation/dictionary.hpp
	g++ $(CXXFLAGS) -c translation/dictionary.cpp

lexer.o: translation/lexer.cpp translation/lexer.hpp
	g++ $(CXXFLAGS) -c translation/lexer.cpp

argumentparser.o: util/argumentparser.cpp util/argumentparser.hpp
	g++ $(CXXFLAGS) -c util/argumentparser.cpp
