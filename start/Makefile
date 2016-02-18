all: start
CPP      = clang++
OBJECTS  = main.o
FLAGS    = -std=c++11 -O3 -Wall -Wextra
INC      = -I$(MATLAB)/extern/include/
LIB      = -L$(MATLAB)/bin/maci64/ -leng -lm -lmat -lmx -lut

start: $(OBJECTS)
	$(CPP) $^ $(FLAGS) $(INC) $(LIB) -o $@
main.o: main.cpp
	$(CPP) $(FLAGS) $(INC) $< -c -o $@

clean:
	rm -rf *.o start *.png
