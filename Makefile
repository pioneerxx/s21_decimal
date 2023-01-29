CC = gcc
FLAGS = -std=c11
FLAG_COV = --coverage
LIBS = -lcheck
TEST_LIBS = -lcheck -lm -lpthread

all: gcov_report

s21_decimal.a:
	$(CC) $(FLAGS) -c s21_add.c s21_div.c s21_floor.c s21_from_decimal_to_float.c s21_from_decimal_to_int.c s21_from_float_to_decimal.c s21_from_int_to_decimal.c s21_is_equal.c s21_is_greater_or_equal.c s21_is_greater.c s21_is_less_or_equal.c s21_is_less.c s21_is_not_equal.c s21_mod.c s21_mul.c s21_negate.c s21_round.c s21_sub.c s21_truncate.c s21_other_funcs.c
	ar rc s21_decimal.a *.o
	ranlib s21_decimal.a

test: s21_decimal.a
	$(CC) $(FLAGS) -c s21_decimal_test.c -o s21_decimal_test.o
	$(CC) s21_decimal_test.o s21_decimal.a $(TEST_LIBS) -o s21_decimal
	./s21_decimal


gcov_report: test
	$(CC) $(FLAGS) --coverage s21_decimal_test.c s21_add.c s21_div.c s21_floor.c s21_from_decimal_to_float.c s21_from_decimal_to_int.c s21_from_float_to_decimal.c s21_from_int_to_decimal.c s21_is_equal.c s21_is_greater_or_equal.c s21_is_greater.c s21_is_less_or_equal.c s21_is_less.c s21_is_not_equal.c s21_mod.c s21_mul.c s21_negate.c s21_round.c s21_sub.c s21_truncate.c s21_decimal.h s21_decimal.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	gcov s21_*.gcda
	gcovr -b
	gcovr
	gcovr --html-details -o report.html
	open report.html

clean:
	rm -rf s21_decimal
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.info
	rm -rf *.html
	rm -rf *.css
	rm -rf test
	rm -rf gcov_test

rebuild: clean all


test2: s21_decimal.a
	$(CC) -c test.c -o test.o
	$(CC) test.o s21_decimal.a -o test
	./test