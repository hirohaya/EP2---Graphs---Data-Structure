CC=gcc
CFLAGS=-c -ansi -pedantic -O2 -Wall
LDFLAGS=
SOURCES=graph.c main.c file.c node.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ep2
EXECUTABLEW=$(EXECUTABLE).exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	
.c.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:          
	rm -f *o $(EXECUTABLE)

#clean for Windows OS
cleanw:
	DEL -f *o $(EXECUTABLEW)

