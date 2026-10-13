CC = gcc
CFLAGS = -O3 -shared -fPIC -lm
TARGET = libkernel.so
SRC = kernel.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(TARGET) $(OBJ)
