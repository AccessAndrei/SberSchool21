
#include "flags_validation.h"
#include "print_func.h"
#include "structure.h"

int parser_for_grep(int argc, char **argv, char *flags[], int size_of_flags,
                    int *flag_pos);

int main(int argc, char **argv) {
  char *flags[] = {"-e", "-i", "-v", "-c", "-l", "-n", "-h", "-s", "-f", "-o"};
  int size = 10;
  int flag_pos;
  int several_files = 0;
  int result = parser_for_grep(argc, argv, flags, size, &flag_pos);
  if (argc - (flag_pos + 2) > 1) several_files = 1;
  if (result) {
    for (int i = flag_pos + 2; argv[i] != NULL; ++i) {
      int size_of_document;
      Line *document = fill_in_structure(argv[i], &size_of_document);
      set_flags_grep(argv, &document, &size_of_document, flag_pos, argv[i],
                     several_files);
      default_print(size_of_document, document, argv, argv[i], flag_pos,
                    several_files);
    }

  } else
    printf("n/a");

  return 0;
}

int e_parser(char **argv, int argc, int *flag_pos) {
  int result = 1;
  int e_amount = 0;
  for (int i = 1; i < argc; ++i) {
    if (!strcmp(argv[i], "-e")) {
      e_amount++;
      *flag_pos = i;
    }
  }
  if (argc - e_amount * 2 - 1 < 1) {
    result = 0;
  }

  return result;
}

int parser_for_grep(int argc, char **argv, char *flags[], int size_of_flags,
                    int *flag_pos) {
  int result = 1;
  int flag_0 = 0;
  *flag_pos = 0;
  if (argc <= 2) {
    result = 0;
    flag_0 = 1;
  }

  if (!strcmp(argv[1], "-e") && !flag_0) {
    result = e_parser(argv, argc, flag_pos);
    if (!result) flag_0 = 1;

  } else if (argv[1][0] == '-' && !flag_0) {
    int flag_1 = 0;
    for (int i = 0; i < size_of_flags; i++) {
      if (!strcmp(flags[i], argv[1]) && !flag_1) {
        flag_1 = 1;
        result = 1;
        flag_0 = 0;
      } else if (!flag_1) {
        result = 0;
      }
      *flag_pos = 1;
    }
  }
  if (!flag_0) {
    for (int i = *flag_pos + 2; i < argc; ++i) {
      int var = access(argv[i], F_OK);
      if (var != 0) result = 0;
    }
  }

  return result;
}
