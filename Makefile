CC = clang++

OBJ = obj/
SRC = src/
INCLUDE = include/
TARGET = mem

compile: $(OBJ)main.o 
	$(CC) -g $(OBJ)main.o -o $(TARGET)

$(OBJ)main.o: $(INCLUDE)memory.h $(SRC)main.cpp $(INCLUDE)log.h
	$(CC) -g -c $(SRC)main.cpp -o  $(OBJ)main.o


test: $(OBJ)main_test.o 
	$(CC) -g  -std=c++11 $(OBJ)main_test.o -o $(TARGET) && ./$(TARGET)

$(OBJ)main_test.o: $(INCLUDE)memory.h $(SRC)main_test.cpp $(INCLUDE)log.h
	$(CC) -g -std=c++11 -c $(SRC)main_test.cpp -o  $(OBJ)main_test.o

clean:
	rm -rf $(OBJ)*