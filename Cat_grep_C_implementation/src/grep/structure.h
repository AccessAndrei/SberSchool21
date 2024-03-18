

#ifndef SBER_PROJECTS_STRUCTURE_H
#define SBER_PROJECTS_STRUCTURE_H
#include "../common/equal.h"
#include "stdlib.h"

typedef struct {
  int line_number;
  char content[10000];
  int is_empty;
  int contains;

} Line;
Line *fill_in_structure(char *filename, int *size_of_structure);
#endif  // SBER_PROJECTS_STRUCTURE_H
