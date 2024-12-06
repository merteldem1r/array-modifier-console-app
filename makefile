# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -I$(shell pwd)/include

# Source files and object files
SRC = src/main.c src/utils/utils.c src/methods/core_methods.c src/methods/search_methods.c src/methods/statistical_methods.c src/methods/transformation_methods.c
OBJ = $(SRC:.c=.o)

# Output executable name
TARGET = array_modifier_app

# Default rule to build the program
all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove compiled files
clean:
	rm -f $(OBJ) $(TARGET)
