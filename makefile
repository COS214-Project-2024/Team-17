main:
	./build.sh

run: main
	./build/Main

test:
	./test.sh

clean:
	rm -rf build

# Define the valgrind rule
val: main
	valgrind --leak-check=full ./main

# Clean Zone.Identifier files
clean_zone:
	find . -name '*:Zone.Identifier' -type f -delete