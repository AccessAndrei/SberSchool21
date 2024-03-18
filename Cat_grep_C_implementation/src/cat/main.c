#include "../common/equal.h"
#include "flags_validation.h"
#include "print_func.h"
#include "structure.h"

void echo();

int main(int argc, char **argv) {
  char *flags[] = {"-b",       "-e",
                   "-n",       "-s",
                   "-t",       "-T",
                   "-E",       "--number-nonblank",
                   "--number", "--squeeze-blank"};
  int size = 10;
  if (argc == 1) {
    echo();
  } else if (input_parser(argv, argc, flags, size)) {
    if (argv[1][0] == '-') {
      for (int i = 2; argv[i] != NULL; ++i) {
        int size_of_document;
        Line *document = fill_in_structure(argv[i], &size_of_document);
        set_flags_cat(argv, &document, &size_of_document);
        default_print(size_of_document, document);
      }
    } else {
      for (int i = 1; argv[i] != NULL; ++i) {
        int size_of_document;
        Line *document = fill_in_structure(argv[i], &size_of_document);
        default_print(size_of_document, document);
      }
    }

  } else
    printf("n/a");

  return 0;
}

void echo() {
  char str[1024];
  while (1) {
    scanf("%1023s", str);
    printf("%s\n", str);
  }
}
