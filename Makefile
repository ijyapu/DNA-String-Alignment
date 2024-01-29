CC = g++
CFLAGS = --std=c++17 -g -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = EDistance.hpp
PROGRAM = EDistance
OBJECTS = EDistance.o main.o
TEST_SRC = test.cpp
TEST_OBJ = test.o
TEST_PROGRAM = test

.PHONY: all clean lint test

all: $(PROGRAM) $(TEST_PROGRAM) $(PROGRAM).a

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROGRAM): main.o $(filter-out test.o, $(OBJECTS))
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(PROGRAM).a: $(filter-out main.o test.o, $(OBJECTS))
	ar rcs $@ $^

$(TEST_PROGRAM): $(TEST_OBJ) $(filter-out main.o, $(OBJECTS))
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

test.o: $(TEST_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(PROGRAM) $(PROGRAM).a $(TEST_PROGRAM)

lint:
	cpplint *.cpp *.hpp
