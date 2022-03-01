BD=../build/
TD=#../tests/
CFLAGS=-c# -Wall -Wextra -Werror
LDFLAGS=#-Wall -Wextra -Werror
LCOVFLAGS=-fprofile-arcs -ftest-coverage
GTESTFLAGS=-lgtest
SRC=main.cpp
OBJECTS=$(addprefix $(BD),$(SRC:.cpp=.o))
CC=g++
CC2=g++
OS:=$(shell uname -s)

ifeq ($(OS), Darwin)
	CC2+= -D OS_MAC
else
	CC2+= -D OS_LINUX
	CHECKFLAGS+= -lrt -lpthread -lm
endif

# all: clean s21_matrix_oop.a
all: main

main: $(BD)main_exe
	./$(BD)main_exe

./$(BD)main_exe: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

debug: $(SRC)
	$(CC) -g $^ -o $(BD)main_exe

s21_matrix_oop.a: $(OBJECTS)
	ar rcs s21_matrix_oop.a $^
	ranlib s21_matrix_oop.a
	cp s21_matrix_oop.a libs21_matrix_oop.a

./$(BD)%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

#### TEST #####
test: $(BD)main_test_exe
	./$^

./$(BD)main_test_exe: s21_matrix_oop.a $(BD)main_test.o
	$(CC2) $(LDFLAGS) $^ -o $@ $(GTESTFLAGS) -ls21_matrix_oop -I./ -L./

#### GCOV #####
gcov_report: $(BD)main_test.o
	$(CC) $(CFLAGS) $(LCOVFLAGS) s21_matrix_oop.cpp -o $(BD)s21_matrix_oop.o
	$(CC) $(LDFLAGS) $(LCOVFLAGS) $(BD)s21_matrix_oop.o $(BD)main_test.o -o $(BD)main_gcov_exe $(GTESTFLAGS)
	./$(BD)main_gcov_exe
	# mv *.gcda *.gcno ./$(BD)
	lcov -t "gcov_report" -o $(BD)gcov_report.info -c -d ./$(BD)
	genhtml -o $(BD)report $(BD)gcov_report.info
	open $(BD)report/index.html

clean: del-lib
	rm -rf ./$(BD)*.o ./$(BD)*_exe ./$(BD)*.dSYM ./$(BD)report
	rm -rf ./$(BD)*.gcno ./$(BD)*.gcda ./$(BD)*.info report/

del-lib:
	rm -f *.a

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ../src/

cpplint:
	cp ../materials/linters/CPPLINT.cfg . && python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp *.h
	rm -f CPPLINT.cfg

leaks:
	leaks --atExit -- ./$(BD)main_exe
