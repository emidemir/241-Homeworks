IDIR = ./Sources/TetrisImp.cpp ./Sources/TetrominoImp.cpp
CC = g++
FLAG = -std=c++11

MAIN1 = ./Mains/driver1.o
MAIN2 = ./Mains/driver2.o

OBJECT = $(IDIR:%.cpp=%.o)

all: fclean run2 run1

driver1: $(MAIN1) $(OBJECT)
	@$(CC) $(FLAG) $(OBJECT) $(MAIN1) -o driver1

driver2:  $(MAIN2) $(OBJECT)
	@$(CC) $(FLAG) $(OBJECT) $(MAIN2) -o driver2

run2: driver2
	@./driver2

run1: driver1
	@./driver1

clean:
	rm -rf $(OBJECT) $(MAIN1) $(MAIN2)

fclean: clean
	rm -rf driver1 driver2

re: fclean all

.PHONY: all driver1 driver2 run2 run1 clean fclean re
