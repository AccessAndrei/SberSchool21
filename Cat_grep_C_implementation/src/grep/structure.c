
#include "structure.h"

Line *fill_in_structure(char *filename, int *size_of_structure) {
  FILE *file = fopen(filename, "r");
  int length_of_array = 10;
  Line *lines = malloc(sizeof(Line) * length_of_array);
  int line_count = 0;

  if (lines == NULL) {
    // Handle memory allocation failure here
    perror("Memory allocation failed");
    fclose(file);
    return NULL;
  }

  while (fgets(lines[line_count].content, sizeof(lines[line_count].content),
               file) != NULL) {
    if (line_count == length_of_array - 1) {
      length_of_array *= 2;
      Line *new_lines = realloc(lines, length_of_array * sizeof(Line));

      if (new_lines == NULL) {
        perror("Memory reallocation failed");
        fclose(file);
        free(lines);
        return NULL;
      }

      lines = new_lines;
    }

    lines[line_count].line_number = line_count + 1;
    if (strlen(lines[line_count].content) == 1) {
      lines[line_count].is_empty = 1;
    } else {
      lines[line_count].is_empty = 0;
    }
    line_count++;
  }

  *size_of_structure = line_count;
  fclose(file);

  return lines;
}
