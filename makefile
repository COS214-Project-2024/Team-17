# Makefile
CXX = g++
CXXFLAGS = -Wall -Wextra -g

# List of source files
SRC = main.cpp $(wildcard Buildings/*.cpp)
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
