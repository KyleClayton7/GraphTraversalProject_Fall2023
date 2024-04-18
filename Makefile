# Specify the target
all: submission

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
submission: main.o prim.o bellman-ford.o
	g++ -Wall main.o prim.o bellman-ford.o -o submission -g -lm

# Specify how the object files should be created from source files
main.o: main.cpp prim.h bellman-ford.h
	g++ -c main.cpp

prim.o: prim.cpp prim.h bellman-ford.h
	g++ -c prim.cpp

bellman-ford.o: bellman-ford.cpp bellman-ford.h
	g++ -c bellman-ford.cpp

run: compile
	./submission inputFile1.txt inputFile2.txt outputFile1.txt outputFile2.txt

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o submission outputFile1.txt outputFile2.txt