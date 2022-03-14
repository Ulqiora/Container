BD=../build/
TESTS=tests/
CFLAGS=-c# -Wall -Wextra -Werror
LDFLAGS=#-Wall -Wextra -Werror
LCOVFLAGS=-fprofile-arcs -ftest-coverage
GTESTFLAGS=-lgtest
SRC=tests/main_test.cpp
OBJECTS=$(addprefix $(BD),$(SRC:.cpp=.o))
CC=g++

all: clean test

./$(BD)%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

debug:
	$(CC) -g $(LDFLAGS) $(SRC) -o $(BD)main_test_exe $(GTESTFLAGS) -I./ -L./

#### TEST #####
./$(BD)%.o: $(TESTS)%.cpp
	$(CC) $(CFLAGS) $< -o $@

test: $(BD)main_test_exe
	./$^

./$(BD)main_test_exe: $(BD)main_test.o
	$(CC) $(LDFLAGS) $^ -o $@ $(GTESTFLAGS) -I./ -L./

#### GCOV #####
gcov_report: $(SRC)
	$(CC) $(LDFLAGS) $(LCOVFLAGS) $^ -o $(BD)main_gcov_exe $(GTESTFLAGS)
	./$(BD)main_gcov_exe
	mv *.gcda *.gcno ./$(BD)
	lcov -t "gcov_report" -o $(BD)gcov_report.info -c -d ./$(BD)
	genhtml -o $(BD)report $(BD)gcov_report.info
	open $(BD)report/index.html

clean:
	rm -rf ./$(BD)*.o ./$(BD)*_exe ./$(BD)*.dSYM ./$(BD)report
	rm -rf ./$(BD)*.gcno ./$(BD)*.gcda ./$(BD)*.info report/

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=noExplicitConstructor --suppress=redundantInitialization \
	--suppress=containerOutOfBounds --suppress=selfAssignment --suppress=negativeIndex ../src/

cpplint:
	cp ../materials/linters/CPPLINT.cfg . && python3 ../materials/linters/cpplint.py --extensions=cpp --filter=-runtime/explicit,-runtime/references */*.cpp *.h; rm -f CPPLINT.cfg

leaks:
	leaks --atExit -- ./$(BD)main_test_exe

valgrind:
	valgrind --undef-value-errors=no --log-file=valgrind-out.txt ../build/main_test_exe
