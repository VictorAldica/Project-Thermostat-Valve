# Needs working g++, if not on path rename CPP variable
			

# Makefile instructions:
# to compile 			-> make all 
# compile and run 		-> make run 
# delete compile file 	-> make clean
# compile without flags -> make fast 
# c++ standard 			-> c++17 

PROGRAM_NAME = ProjectThermostatValve

CSTD = c++17

flags_all = -std=$(CSTD) -g -O0 -Wall -Wextra -fsanitize=address,undefined,signed-integer-overflow
flags_fast = -std=$(CSTD) -O2

SCR_PARAMS = src/*.cpp

# make all creates sanitized binary, overflows, illegal memory accesses and undefined behaviour raise an exception
all: $(sources)
	g++ $(flags_all)  $(SCR_PARAMS) -o $(PROGRAM_NAME).out

# make fast compiles with -O2 flag
fast: $(sources)
	g++ $(flags_fast)  $(SCR_PARAMS) -o $(PROGRAM_NAME).out
  
# removes a.out file
clean:
	rm $(PROGRAM_NAME).out

run: $(sources)
	g++ $(flags_all) $(SCR_PARAMS) -o $(PROGRAM_NAME).out
	./$(PROGRAM_NAME).out
