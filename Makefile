CC=gcc

ifeq ($(shell uname), Linux)
	LFLAGS = -pthread -lcheck_pic -lrt -lm -lsubunit
else ifeq ($(shell uname), Darwin)
	LFLAGS = -pthread -lm -lcheck
endif

CFLAGS = -Wall -Werror -Wextra -std=c11
TEST= ./tests/test*.c

all: s21_decimal.a gcov_report test style_n

s21_decimal.a:
	$(CC) $(CFLAGS) -c s21_*.c
	ar rcs s21_decimal.a *.o

test: s21_decimal.a
	$(CC) $(CFLAGS) s21_*.c ./s21_decimal.a $(TEST) $(LFLAGS) -o test
	./test

gcov_report: s21_decimal.a
	$(CC) $(CFLAGS) --coverage s21_*.c $(TEST) $(LFLAGS) -o gcov_test
	./gcov_test
	lcov -t "gcov-test" -o report.txt -c -d .
	genhtml -o report report.txt
	open ./report/index.html

clean:
	rm -rf *.a *.gch *.o *.gcno *.gcda gcov_test report.txt report test

reduild:
	make clean
	make all

style_n:
	clang-format -style=Google -n *.c
	clang-format -style=Google -n *.h

	clang-format -style=Google -n tests/test*.c
	clang-format -style=Google -n tests/test*.h

style_i:
	clang-format -style=Google -i s21_*.c
	clang-format -style=Google -i s21_*.h

	clang-format -style=Google -i tests/test*.c
	clang-format -style=Google -i tests/test*.h

leaks:
	leaks --atExit -- ./test

val:
	valgrind --tool=memcheck --leak-check=yes ./test

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem ./*.c *.h ./tests/*.c ./tests/*.h