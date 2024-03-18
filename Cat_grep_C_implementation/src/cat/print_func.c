
#include "print_func.h"

void default_print(int size_of_document, Line *document) {
  for (int j = 0; j < size_of_document; j++) {
    printf("%s", document[j].content);
  }
  free(document);
}
