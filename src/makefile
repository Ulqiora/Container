BD=#../build/
TD=#../tests/
CFLAGS=-c #-Wall -Wextra -Werror
LDFLAGS=#-Wall -Wextra -Werror
GTESTFLAGS=-lgtest -lpthread
CC=g++

all: clean s21_container.a

main: $(BD)main_exe
	./$(BD)main_exe

./$(BD)main_exe: $(BD)s21_matrix_oop.o
	$(CC) $^ -o $@

debug: s21_matrix_oop.cpp
	$(CC) -g $^ -o $(BD)main_exe

s21_container.a: $(BD)vector.o
	ar rcs s21_matrix_oop.a $^
	ranlib s21_matrix_oop.a
	cp s21_matrix_oop.a libs21_matrix_oop.a

./$(BD)%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

#### TEST #####
test: $(BD)main_test_exe
	./$^

./$(BD)main_test_exe: s21_container.a $(BD)main_test.o
	$(CC) $(LDFLAGS) $^ -o $@ $(GTESTFLAGS) -ls21_matrix_oop -I./ -L./

clean: del-lib
	rm -rf ./$(BD)*.o ./$(BD)*_exe ./$(BD)*.dSYM

del-lib:
	rm -f *.a

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction ../src/

cpplint:
	python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp *.hpp
