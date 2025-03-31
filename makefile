# Compiler, c++ version and flags
CC = g++
STD = -std=c++20
CXXFLAGS = -I . $(STD)

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

# Test directories
TEST_DIR = test
INPUT_DIR = $(TEST_DIR)/input
OUTPUT_DIR = $(TEST_DIR)/output

# Test target
test: $(PROG)
	@echo "Running tests..."
	@for test_file in $(INPUT_DIR)/*; do \
		if [ -f "$$test_file" ]; then \
			base_name=$$(basename $$test_file); \
			echo "Running test $$base_name"; \
			temp_output=$$(mktemp); \
			./$(PROG) < $$test_file > $$temp_output; \
			if [ -f "$(OUTPUT_DIR)/$$base_name" ]; then \
				if diff -w $$temp_output $(OUTPUT_DIR)/$$base_name > /dev/null; then \
					echo "✅ Test $$base_name passed!"; \
				else \
					echo "❌ Test $$base_name failed!"; \
					echo "--- Expected output:"; \
					cat $(OUTPUT_DIR)/$$base_name; \
					echo ""; \
					echo "--- Actual output:"; \
					cat $$temp_output; \
				fi; \
			else \
				echo "⚠️ No expected output file for test $$base_name"; \
				echo "--- Program output:"; \
				cat $$temp_output; \
			fi; \
			rm $$temp_output; \
			echo ""; \
		fi; \
	done; \
	if ! ls $(INPUT_DIR)/* 1> /dev/null 2>&1; then \
		echo "No test files found. Create files in $(INPUT_DIR)/"; \
	fi

# Clean up generated files
clean:
	rm -f $(PROG) $(OBJ)

# Phony targets to prevent conflicts with files named 'all', 'clean', or 'test'
.PHONY: all clean test