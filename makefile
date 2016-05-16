CC=g++
CC_FLAGS=-Wall -Werror -ansi -pedantic
EXEC=rshell

all:
	mkdir -p ./bin
	$(CC) $(CFLAGS) ./src/main.cpp -o ./src/rshell.cpp -o ./src/Arguments.cpp -o ./src/Base.cpp -o ./src/Connector.cpp -o ./src/Executable.cpp -o ./src/Parsed.cpp -o ./bin/rshell
	
rshell:
	$(CC) $(CFLAGS) ./src/rshell.cpp -o 
	
clean:
	rm -rf ./bin