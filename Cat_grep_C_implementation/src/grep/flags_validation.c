

#include "flags_validation.h"

void b_flag(Line *document, int size_of_document);

void e_flag(Line *document, int size_of_document, char **argv, int flag_pos);

void shift_1(Line *line, int len, int j);

void v_flag(Line *document, int size_of_document, char **argv);

void f_flag(Line *document, int size_of_document, char **argv);

void n_flag(Line *document, int size_of_document);

void s_flag(Line **document, int *size_of_document);

void t_flag(Line *document, int size_of_document);

void init_struct(int size_of_document, Line *document);

void i_flag(Line *document, int size_of_document, char **argv);

void o_flag(Line *document, int size_of_document, char **argv, char *filename,
            int flag);

void init_struct_1(int size_of_document, Line *document);

void flags_decomposition(char sym, int *flags) {
  switch (sym) {
    case 'e': {
      flags[0] = 1;
      break;
    }
    case 'i': {
      flags[1] = 1;
      break;
    }
    case 'v': {
      flags[2] = 1;
      break;
    }
    case 'c': {
      flags[3] = 1;
      break;
    }
    case 'l': {
      flags[4] = 1;
      break;
    }
    case 'n': {
      flags[5] = 1;
      break;
    }
    case 'h': {
      flags[6] = 1;
      break;
    }
    case 's': {
      flags[7] = 1;
      break;
    }
    case 'f': {
      flags[8] = 1;
      break;
    }
    case 'o': {
      flags[9] = 1;
      break;
    }
  }
}

void set_flags_grep(char **argv, Line **document, int *size_of_document,
                    int flag_pos, char *filename, int flag) {
  int flags[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // b-e-n-s-t-T-v-E
  init_struct(*size_of_document, *document);
  if (argv[1][0] == '-' && argv[1][1] != '-') {
    for (int i = 1; argv[1][i] != '\0'; ++i) {
      char sym = argv[1][i];
      flags_decomposition(sym, flags);
    }
  }
  if (flags[0] == 1)
    e_flag(*document, *size_of_document, argv, flag_pos);
  else if (flags[1] == 1) {
    i_flag(*document, *size_of_document, argv);
  } else if (flags[2] == 1) {
    v_flag(*document, *size_of_document, argv);
  } else if (flags[3] == 1) {
    e_flag(*document, *size_of_document, argv, flag_pos);
  } else if (flags[4] == 1) {
    e_flag(*document, *size_of_document, argv, flag_pos);

  } else if (flags[5] == 1)
    e_flag(*document, *size_of_document, argv, flag_pos);
  else if (flags[6] == 1)
    e_flag(*document, *size_of_document, argv, flag_pos);
  else if (flags[7] == 1)
    e_flag(*document, *size_of_document, argv, flag_pos);
  else if (flags[8] == 1)
    f_flag(*document, *size_of_document, argv);
  else if (flags[9] == 1)
    o_flag(*document, *size_of_document, argv, filename, flag);
  else
    e_flag(*document, *size_of_document, argv, flag_pos);
}

void i_flag(Line *document, int size_of_document, char **argv) {
  char *pattern = argv[2];
  regex_t regex;

  regcomp(&regex, pattern, REG_ICASE | REG_EXTENDED);

  for (int i = 0; i < size_of_document; ++i) {
    char *str = document[i].content;
    int ret = regexec(&regex, str, 0, NULL, 0);
    if (ret == 0) {
      document[i].contains = 1;
    }
  }
  regfree(&regex);
}

void e_flag(Line *document, int size_of_document, char **argv, int flag_pos) {
  if (flag_pos != 0) {
    for (int i = 2; i <= flag_pos + 1; i += 2) {
      for (int j = 0; j < size_of_document; ++j) {
        if (strstr(document[j].content, argv[i]) != NULL)
          document[j].contains = 1;
      }
    }

  } else {
    for (int j = 0; j < size_of_document; ++j) {
      if (strstr(document[j].content, argv[1]) != NULL)
        document[j].contains = 1;
    }
  }
}

void v_flag(Line *document, int size_of_document, char **argv) {
  init_struct_1(size_of_document, document);
  for (int i = 0; i < size_of_document; ++i) {
    if (strstr(document[i].content, argv[2])) {
      document[i].contains = 0;
    }
  }
}

void f_flag(Line *document, int size_of_document, char **argv) {
  FILE *patterns = fopen(argv[2], "r");
  char patternBuffer[256];
  regex_t regex;

  while (fgets(patternBuffer, sizeof(patternBuffer), patterns) != NULL) {
    size_t patternLength = strlen(patternBuffer);
    if (patternBuffer[patternLength - 1] == '\n') {
      patternBuffer[patternLength - 1] = '\0';
    }
    if (regcomp(&regex, patternBuffer, REG_EXTENDED) != 0) {
      fprintf(stderr, "Error compiling regular expression for pattern: %s\n",
              patternBuffer);
      continue;
    }

    for (int i = 0; i < size_of_document; ++i) {
      if (regexec(&regex, document[i].content, 0, NULL, 0) == 0) {
        document[i].contains = 1;
      }
    }

    regfree(&regex);
  }

  fclose(patterns);
}

void o_flag(Line *document, int size_of_document, char **argv, char *filename,
            int flag) {
  regex_t regex;
  if (regcomp(&regex, argv[2], REG_EXTENDED) != 0) {
    fprintf(stderr, "Error compiling regular expression\n");
    return;
  }
  for (int i = 0; i < size_of_document; i++) {
    regmatch_t matches[1];
    if (regexec(&regex, document[i].content, 1, matches, 0) == 0) {
      // Match found, print the matched portion
      int matchStart = matches[0].rm_so;
      int matchEnd = matches[0].rm_eo;

      if (matchStart >= 0 && matchEnd >= 0) {
        if (flag) {
          printf("%s:%.*s\n", filename, matchEnd - matchStart,
                 document[i].content + matchStart);
        } else {
          printf("%.*s\n", matchEnd - matchStart,
                 document[i].content + matchStart);
        }
      }
    }
  }

  regfree(&regex);
}

void init_struct(int size_of_document, Line *document) {
  for (int i = 0; i < size_of_document; ++i) {
    document[i].contains = 0;
  }
}

void init_struct_1(int size_of_document, Line *document) {
  for (int i = 0; i < size_of_document; ++i) {
    document[i].contains = 1;
  }
}