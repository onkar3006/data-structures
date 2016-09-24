TARGET = test
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

LDIR = lib
SDIR = src

.PHONY: default all clean

default: $(TARGET)
all: default

SRC = $(wildcard */*.c)
OBJECTS = $(patsubst %.c, %.o, $(SRC))
HEADERS = $(LDIR)/*.h

$(LDIR)/%.o: $(LDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(SDIR)/%.o: $(SDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f $(LDIR)/*.o
	-rm -f $(SDIR)/*.o
	-rm -f *.o
	-rm -f $(TARGET)
