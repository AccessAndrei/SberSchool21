#include "structure.h"

#ifndef SBER_PROJECTS_PRINT_FUNC_H
#define SBER_PROJECTS_PRINT_FUNC_H

void default_print(int size_of_document, Line *document, char **argv,
                   char *filename, int flag_pos, int flag);

void print_with_name_of_file(int size_of_document, Line *document,
                             char *filename, int flag);

void print_with_amount(int size_of_document, Line *document, char *filename,
                       int flag);

void print_with_number_of_line(int size_of_document, Line *document,
                               char *filename, int flag);

void print_name_of_file_only(int size_of_document, Line *document,
                             char *filename);

#endif
