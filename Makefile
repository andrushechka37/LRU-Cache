CC = clang++

OBJ = obj/
SRC = src/
INCLUDE = include/
TARGET = mem

compile: $(OBJ)main.o $(OBJ)memory.o
	$(CC) -g $(OBJ)main.o $(OBJ)memory.o -o $(TARGET)

$(OBJ)main.o: $(INCLUDE)memory.h $(SRC)main.cpp $(INCLUDE)log.h
	$(CC) -g -c $(SRC)main.cpp -o  $(OBJ)main.o

$(OBJ)memory.o: $(INCLUDE)memory.h $(INCLUDE)log.h $(SRC)memory.cpp
	$(CC) -g -c $(SRC)memory.cpp -o $(OBJ)memory.o

clean:
	rm -rf $(OBJ)*