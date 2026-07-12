CC      = cl65
TARGET  = pottest.prg
SRC     = src/main.c

CFLAGS  = -Oirs -t c64

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	rm -f $(TARGET)
	rm -f src/*.o

.PHONY: all clean
