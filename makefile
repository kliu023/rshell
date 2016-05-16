CC=g++
CFLAGS=-Wall -Werror -ansi -pedantic


all: rshell
	# $(CC) $(CFLAGS) ./src/main.cpp ./src/rshell.cpp ./src/Arguments.cpp ./src/Base.cpp ./src/Connector.cpp ./src/Executable.cpp ./src/Parsed.cpp -o ./bin/rshell
	
rshell: mkdir Base.o Executable.o Arguments.o Connector.o  Parsed.o main.o 
	$(CC) $(CFLAGS) ./bin/Base.o ./bin/Executable.o ./bin/Arguments.o ./bin/Connector.o ./bin/Parsed.o ./bin/main.o -o ./bin/rshell
	
main.o: ./src/main.cpp
	$(CC) $(CFLAGS) ./src/main.cpp -c -o ./bin/main.o
	
rshell.o: ./src/rshell.cpp
	$(CC) $(CFLAGS) ./src/rshell.cpp -c -o ./bin/rshell.o
	
Parsed.o: ./src/Parsed.cpp
	$(CC) $(CFLAGS) ./src/Parsed.cpp -c -o ./bin/Parsed.o
	
Arguments.o: ./src/Arguments.cpp
	$(CC) $(CFLAGS) ./src/Arguments.cpp -c -o ./bin/Arguments.o
	
Connector.o: ./src/Connector.cpp
	$(CC) $(CFLAGS) ./src/Connector.cpp -c -o ./bin/Connector.o
	
Executable.o: ./src/Executable.cpp
	$(CC) $(CFLAGS) ./src/Executable.cpp -c -o ./bin/Executable.o
	
Base.o: ./src/Base.cpp
	$(CC) $(CFLAGS) ./src/Base.cpp -c -o ./bin/Base.o

mkdir:
	mkdir -p ./bin
	

clean:
	rm -rf ./bin
	
	
# all: hello

# hello: main.o factorial.o hello.o
#     $(CC) main.o factorial.o hello.o -o hello

# main.o: main.cpp
#     $(CC) $(CFLAGS) main.cpp

# factorial.o: factorial.cpp
#     $(CC) $(CFLAGS) factorial.cpp

# hello.o: hello.cpp
#     $(CC) $(CFLAGS) hello.cpp

# clean:
#     rm *o hello

