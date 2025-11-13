# Compiler, c++ version and flags
CC = g++-15
STD = -std=c++20
CXXFLAGS = -O2 -Wall $(STD)

# Target executable
PROG = a

# Source and object files
SRC = a.cpp
OBJ = a.o

# Default target
all: $(PROG)

# Link the object file to create the executable
$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)

# Compile the source file into an object file
$(OBJ): $(SRC)
	$(CC) -c $< $(CXXFLAGS)

# Run the executable
run: $(PROG)
	./$(PROG)

# Clean up generated files
clean:
	rm -f $(PROG) $(OBJ)

# Phony targets to prevent conflicts with files named 'all', 'clean', or 'test'
.PHONY: all clean run
