CC = gcc

ifdef CROSS_COMPILE
	CC = $(CROSS_COMPILE)gcc
endif

TARGET = writer
OBJS = writer.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

writer.o: writer.c
	$(CC) -c writer.c -o writer.o

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean