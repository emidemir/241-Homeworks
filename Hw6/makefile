CC = g++
FLAG = --std=c++11 -Wall
DRIVER1 = ./Drivers/driver1.cpp
DRIVER1OBJ = driver1.o
IMPFILE = ./Implementations/PFArray.cpp
IMPFILEOBJ = PFArray.o

all: compile run1 clean

compile: driver1 PFArray
	@ $(CC) $(FLAG) -o program1 $(DRIVER1OBJ) $(IMPFILEOBJ)

run1:
	@ ./program1

driver1:
	@ $(CC) $(FLAG) -c $(DRIVER1)

PFArray:
	@ $(CC) $(FLAG) -c $(IMPFILE)

clean:
	@rm -f $(DRIVER1OBJ)
	@rm -f $(IMPFILEOBJ)
	@rm -f program1