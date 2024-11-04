main: *.o
	g++ -o main *.o
	g++ *.cpp -o main
*.o: *.cpp
	g++ -c *.cpp
run: main
	./main
clean:
	rm *.o main
val: main
	valgrind --leak-check=full ./main



# CC = g++
# CFLAGS = -Wall -Werror
# LFLAGS = -static
# TARGET = GoRide
# OBJECTS = Bike.o Tricycle.o main.o
# # Linking all the object code:
# all: $(OBJECTS)
# $(CC) $(LFLAGS) $(OBJECTS) -o $(TARGET)
# # Dependencies:
# Bike.o: Bike.h Wheel.h
# Tricycle.o: Tricycle.h Wheel.h
# main.o: Bike.h Tricycle.h
# # Compilation rule:
# %.o: %.cpp
# $(CC) $< $(CFLAGS) -c -o $@
# # Custom commands:
# clean:
# rm -f $(TARGET) $(OBJS) *~ # deleting executable, .o’s and backups
# run:
# ./$(TARGET) # executing the program