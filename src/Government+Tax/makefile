# Define the C++ compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# The binary name
TARGET = Main

# List of source files
SOURCES = $(wildcard *.cpp)

# The object files
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -rf *.o

run: all
	./Main

valgrind: $(TARGET)
	valgrind --leak-check=full --show-reachable=yes ./$(TARGET)
