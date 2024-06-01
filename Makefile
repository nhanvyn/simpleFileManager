CC=gcc

CFLAGS=-Wall -g

TARGET=file_manager

all: $(TARGET)

$(TARGET): main.o operation.o
	$(CC) main.o operation.o -o $(TARGET)

# Compile the source file
main.o: main.c operation.h
	$(CC) $(CFLAGS) -c main.c -o main.o

operation.o: operation.c operation.h
	$(CC) $(CFLAGS) -c operation.c -o operation.o

# Clean the build artifacts
clean:
	rm -f main.o operation.o $(TARGET)
