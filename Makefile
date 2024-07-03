CC = riscv64-linux-gnu-gcc
SOURCE = task.c
OBJECT = task.o
CFLAGS = -static
TARGET = task
all: $(TARGET)
$(TARGET): task.o
	$(CC) $(CFLAGS) -o $@ $^
$(OBJECT): $(SOURCE)
	$(CC) $(CFLAGS) -c $^
.PHONY: clean
clean:
	rm -rf *.o task