C=g++
CC_FLAGS=-Wall -Werror -ansi -pedantic
EXEC=rshell
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

all: Arguments.o Base.o Connector.o Executable.o Parsed.o rshell.o
#$(EXEC): $(OBJECTS)
#	$(CC) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

#%.o: %.h
#	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -rf *o all

#DEPS = split.h

#all: Lock.o DBC.o Trace.o

#%.o: %.cpp $(DEPS)
#    $(CC) -o $@ $< $(CFLAGS)

#clean:
#    rm -rf *o all
