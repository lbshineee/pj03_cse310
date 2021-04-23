EXEC = dijkstra
CC = g++ -O3
CFLAGS = -c -Wall

# $ (EXEC) has the value of shell variable EXEC, which is run.
# run depends on the files main.o util.o heap.o graph.o
$(EXEC) :main.o util.o heap.o graph.o

# run is created by the command gcc -o run main.o util.o heap.o graph.o
# note that the TAB before $(CC) is REQUIRED...
	$(CC) -o $(EXEC) main.o util.o heap.o graph.o

# main.o depends on the files main.h main.c
main.o :main.cpp main.h util.h heap.h graph.h
# main.o is created by the command gcc -c -Wall main.cpp
# note that the TAB before $(CC) is REQUIRED...
	$(CC) $(CFLAGS) main.cpp

graph.o :graph.h graph.cpp
	$(CC) $(CFLAGS) graph.cpp

util.o 	:util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

heap.o  :heap.h heap.cpp
	$(CC) $(CFLAGS) heap.cpp

clean:
		rm *.o run 
