# # Define the source files and headers
# SOURCES := $(shell find . -name '*.cpp')
# HEADERS := $(shell find . -name '*.h')
# OBJECTS := $(SOURCES:.cpp=.o) 

# # Define the target
# main: $(OBJECTS)
# 	g++ -o main $(OBJECTS)

# # Define the object file rule
# # This rule handles source files in subdirectories
# %.o: %.cpp $(HEADERS)
# 	g++ -c $< -o $@

# # Define the run rule
# run: main
# 	./main

# # Define the clean rule
# clean:
# 	rm -f $(OBJECTS) main

# # Define the valgrind rule
# val: main
# 	valgrind --leak-check=full ./main




# Makefile
CXX = g++
CXXFLAGS = -Wall -Wextra -g

# List of source files
SRC = main.cpp ../Buildings/Building.cpp $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

# Target executable
TARGET = my_program

# Default target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean the object files and the target
clean:
	rm -f $(OBJ) $(TARGET)