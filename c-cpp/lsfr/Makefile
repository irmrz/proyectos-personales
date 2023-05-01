CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g
OBJECTS = lsfr.o 
TARGET = lsfr

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS) lsfr.c
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) lsfr.c

valgrind: $(TARGET)
	valgrind --show-reachable=yes --leak-check=full ./$(TARGET) input/example_graph_1.in

clean:
	rm -f $(TARGET) $(OBJECTS)



