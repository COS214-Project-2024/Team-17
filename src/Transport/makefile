# Define the source files and headers
SOURCES := $(shell find . -name '*.cpp' | grep -v 'main.cpp')
HEADERS := $(shell find . -name '*.h')
OBJECTS := $(SOURCES:.cpp=.o) 

# Define the target
main: $(OBJECTS)
	g++ -o main $(OBJECTS)

# Define the object file rule
# This rule handles source files in subdirectories
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

# Define the run rule
run: main
	./main

# Define the clean rule
clean:
	rm -f $(OBJECTS) main

# Define the valgrind rule
val: main
	valgrind --leak-check=full ./main