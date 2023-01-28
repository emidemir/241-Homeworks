CC = g++
FLAG = --std=c++11 -Wall

all: run2 run1 clean

run1: compile1D compileAdapter compileVector compileTetromino
	@	$(CC) $(FLAG) -c ./Drivers/driver1.cpp
	@	$(CC) $(FLAG) -o program1 driver1.o TetrisVector.o TetrisAdapter.o TetrisArray1D.o Tetromino.o
	@	./program1

run2: compile1D compileAdapter compileVector compileTetromino
	@	$(CC) $(FLAG) -c ./Drivers/driver2.cpp
	@	$(CC) $(FLAG) -o program2 driver2.o TetrisVector.o TetrisAdapter.o TetrisArray1D.o Tetromino.o
	@	./program2

compile1D: ./Implementations/TetrisArray1D.cpp
	@ $(CC) $(FLAG) -c ./Implementations/TetrisArray1D.cpp

compileAdapter: ./Implementations/TetrisAdapter.cpp
	@ $(CC) $(FLAG) -c ./Implementations/TetrisAdapter.cpp

compileVector: ./Implementations/TetrisVector.cpp
	@ $(CC) $(FLAG) -c ./Implementations/TetrisVector.cpp

compileTetromino: ./Implementations/Tetromino.cpp
	@	$(CC) $(FLAG) -c ./Implementations/Tetromino.cpp

clean:
	@	rm -f TetrisVector.o
	@	rm -f Tetromino.o
	@	rm -f TetrisAdapter.o
	@	rm -f TetrisArray1D.o
	@	rm -f driver1.o
	@	rm -f driver2.o
	@	rm -f program1
	@	rm -f program2
