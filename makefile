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
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./build/Main

# Clean Zone.Identifier files
clean_zone:
	find . -name '*:Zone.Identifier' -type f -delete