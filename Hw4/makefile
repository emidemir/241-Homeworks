all: compile run clean

compile: dayOfYearSet.hpp dayOfYearSet.cpp main.cpp
	@g++ -Wall -o dayOfYearSet.o -c dayOfYearSet.cpp
	@g++ -Wall -o main.o -c main.cpp
	@g++ -Wall -o program dayOfYearSet.o main.o

run:	program
	@./program
clean:
	@rm program