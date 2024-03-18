GCC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
CAT = flags_validation.c main.c print_func.c structure.c ../common/equal.c
ALIAS = s21_cat


.PHONY: s21_clean clean

s21_cat:
	$(GCC) $(FLAGS) $(CAT) -o $(ALIAS)
clean:
	rm -rf $(ALIAS)