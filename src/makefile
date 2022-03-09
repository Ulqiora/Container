BD=#../build/
TD=#../tests/
CFLAGS=-c #-Wall -Wextra -Werror
LDFLAGS=#-Wall -Wextra -Werror
GTESTFLAGS=-lgtest -lpthread -lm
OBJECTS= main.cpp
CC=g++

all: clean main

main: $(BD)main_exe
	./$(BD)main_exe

./$(BD)main_exe: $(BD)main.o
	$(CC) $^ -o $@

debug: main.cpp
	$(CC) -g $^ -o $(BD)debug

./$(BD)%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

#### TEST #####
test: clean $(BD)main_test_exe
	./$(BD)main_test_exe

./$(BD)main_test_exe: $(BD)main_test.o
	$(CC) $(LDFLAGS) $^ -o $@ $(GTESTFLAGS) -I./ -L./

clean:
	rm -rf ./$(BD)*.o ./$(BD)*_exe ./$(BD)*.dSYM

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction ../src/

cpplint:
	python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp *.hpp
