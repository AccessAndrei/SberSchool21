#include "../common/equal.h"
#include "print_func.h"
#include "structure.h"

#ifndef SBER_PROJECTS_FLAGS_VALIDATION_H
#define SBER_PROJECTS_FLAGS_VALIDATION_H
void flags_decomposition(char sym, int* flags);
void set_flags_cat(char** argv, Line** document, int* size_of_document);
void E_flag(Line* document, int size_of_document);
void b_flag(Line* document, int size_of_document);
void shift_1(Line* line, int len, int j);
void v_flag(Line* document, int size_of_document);
void shift_7(Line* line, int len);

#endif
