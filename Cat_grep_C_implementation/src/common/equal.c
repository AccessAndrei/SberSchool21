
#include "equal.h"

int input_parser(char **argv, int argc, char *flag[], int size_of_flags) {
  int result = 1;
  int flag_0 = 0;
  if (argc < 2) {
    flag_0 = 1;
    result = 0;
  }

  if (argv[1][0] == '-' && flag_0 == 0) {
    for (int i = 0; i < size_of_flags; i++) {
      if (strcmp(flag[i], argv[1]) == 0) {
        result = 1;
        break;
      } else {
        result = 0;
        if (i == size_of_flags - 1) {
          flag_0 = 1;
        }
      }
    }
    if (flag_0 == 0) {
      for (int i = 2; argv[i] != NULL; i++) {
        result = access(
            argv[i], F_OK);  // returns 0 if file got reached; -1 - if did not
        if (result == 0)
          result = 1;
        else {
          result = 0;
          break;
        }
      }
    }
  } else if (flag_0 == 0) {
    for (int i = 1; argv[i] != NULL; i++) {
      int var;
      var = access(argv[i],
                   F_OK);  // returns 0 if file got reached; -1 - if did not
      if (var == 0)
        result = 1;
      else {
        result = 0;
        break;
      }
    }
  }
  return result;
}
