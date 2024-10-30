main:
	./build.sh

run: main
	./build/Main

test:
	./test.sh

clean:
	rm -rf build