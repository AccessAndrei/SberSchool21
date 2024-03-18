GCC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11

CAT = flags_validation.c main.c print_func.c structure.c ../common/equal.c
ALIAS = s21_grep


.PHONY: s21_clean clean

s21_grep:
	$(GCC) $(FLAGS) $(CAT) -o $(ALIAS)
clean:
	rm -rf $(ALIAS)