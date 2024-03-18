

#include "flags_validation.h"

void b_flag(Line *document, int size_of_document);

void e_flag(Line *document, int size_of_document);

void shift_1(Line *line, int len, int j);

void v_flag(Line *document, int size_of_document);

void n_flag(Line *document, int size_of_document);

void s_flag(Line **document, int *size_of_document);

void t_flag(Line *document, int size_of_document);

void flags_decomposition(char sym, int *flags) {
  switch (sym) {
    case 'b': {
      flags[0] = 1;
      break;
    }
    case 'e': {
      flags[1] = 1;
      break;
    }
    case 'n': {
      flags[2] = 1;
      break;
    }
    case 's': {
      flags[3] = 1;
      break;
    }
    case 't': {
      flags[4] = 1;
      break;
    }
    case 'T': {
      flags[5] = 1;
      break;
    }
    case 'E': {
      flags[6] = 1;
      break;
    }
  }
}

void set_flags_cat(char **argv, Line **document, int *size_of_document) {
  int flags[] = {0, 0, 0, 0, 0, 0, 0};  // b-e-n-s-t-T-v-E
  if (argv[1][0] == '-' && argv[1][1] != '-') {
    for (int i = 1; argv[1][i] != '\0'; ++i) {
      char sym = argv[1][i];
      flags_decomposition(sym, flags);
    }
  } else if (argv[1][0] == '-' && argv[1][1] == '-') {
    if (strcmp(argv[1], "--squeeze-blank") == 0) {
      flags[3] = 1;
    } else if (strcmp(argv[1], "--number-nonblank") == 0)
      flags[0] = 1;
    else
      flags[2] = 1;
  }
  if (flags[0] == 1) b_flag(*document, *size_of_document);
  if (flags[1] == 1) {
    E_flag(*document, *size_of_document);
    v_flag(*document, *size_of_document);
  }
  if (flags[2] == 1) {
    n_flag(*document, *size_of_document);
  }
  if (flags[3] == 1) {
    s_flag(document, size_of_document);
  }
  if (flags[4] == 1) {
    t_flag(*document, *size_of_document);
    v_flag(*document, *size_of_document);
  }
  if (flags[5] == 1) t_flag(*document, *size_of_document);
  if (flags[6] == 1) E_flag(*document, *size_of_document);
}

void b_flag(Line *document, int size_of_document) {
  int number = 1;
  for (int i = 0; i < size_of_document; ++i) {
    if (document[i].is_empty == 0) {
      char numberStr[20];
      snprintf(numberStr, sizeof(numberStr), "%6d\t", number);
      number++;
      char combinedStr[10000];
      strcpy(combinedStr, numberStr);
      strcat(combinedStr, document[i].content);
      strcpy(document[i].content, combinedStr);
    }
  }
}

void E_flag(Line *document, int size_of_document) {
  for (int i = 0; i < size_of_document; ++i) {
    char *newline_pos = strchr(document[i].content, '\n');

    if (newline_pos != NULL) {
      int index = newline_pos - document[i].content;
      memmove(&document[i].content[index + 1], &document[i].content[index],
              strlen(document[i].content) - index);
      document[i].content[index] = '$';
      document[i].content[index + 2] = '\0';
    }
  }
}

void v_flag(Line *document, int size_of_document) {
  for (int i = 0; i < size_of_document; ++i) {
    int len = strlen(document[i].content);
    for (int j = 0; document[i].content[j] != '\0'; ++j) {  // remake with while
      if ((document[i].content[j] < 32 && document[i].content[j] != 10 &&
           document[i].content[j] != 9 && document[i].content[j] >= 0)) {
        char sym = document[i].content[j];
        shift_1(&document[i], len, j);
        len++;
        document[i].content[j] = '^';
        j++;
        document[i].content[j] = sym + 64;
      } else if (document[i].content[j] == 127) {
        shift_1(&document[i], len, j);
        len++;
        document[i].content[j] = '^';
        j++;
        document[i].content[j] = '?';
      } else if (((unsigned char)document[i].content[j] > 127 &&
                  (unsigned char)document[i].content[j] < 160) ||
                 ((unsigned char)document[i].content[j] == 255)) {
        char sym = document[i].content[j];
        shift_1(&document[i], len, j);
        len++;
        document[i].content[j] = 'M';
        j++;
        shift_1(&document[i], len, j);
        len++;
        document[i].content[j] = '-';
        j++;
        shift_1(&document[i], len, j);
        len++;
        document[i].content[j] = '^';
        j++;
        document[i].content[j] = sym - 64;
      } else if (((unsigned char)document[i].content[j] >= 160 &&
                  (unsigned char)document[i].content[j] <= 254)) {
        char sym = document[i].content[j];
        shift_1(&document[i], len, j);
        len++;
        document[i].content[j] = 'M';
        j++;
        shift_1(&document[i], len, j);
        len++;
        document[i].content[j] = '-';
        j++;
        document[i].content[j] = sym - 128;
      }
    }
    document[i].content[len] = '\0';
  }
}

void n_flag(Line *document, int size_of_document) {
  for (int i = 0; i < size_of_document; ++i) {
    char numberStr[20];
    snprintf(numberStr, sizeof(numberStr), "%6d\t", document[i].line_number);
    char combinedStr[10000];
    strcpy(combinedStr, numberStr);
    strcat(combinedStr, document[i].content);
    strcpy(document[i].content, combinedStr);
  }
}

void s_flag(Line **document, int *size_of_document) {
  int flag_squeeze = 0;
  int index = 0;
  Line *_array = malloc(sizeof(Line) * (*size_of_document));
  for (int i = 0; i < *size_of_document; ++i) {
    if ((*document)[i].is_empty == 1) {
      flag_squeeze++;
    } else {
      flag_squeeze = 0;
    }
    if (flag_squeeze == 1 || flag_squeeze == 0) {
      _array[index] = (*document)[i];
      index++;
    }
  }
  free(*document);
  *document = _array;
  *size_of_document = index;
}

void t_flag(Line *document, int size_of_document) {
  for (int i = 0; i < size_of_document; ++i) {
    int len = strlen(document[i].content);
    for (int j = 0; j < len; ++j) {
      if (document[i].content[j] == 9) {
        shift_1(&document[i], len, j);
        len++;
        document[i].content[j] = '^';
        j++;
        document[i].content[j] = 'I';
      }
    }
    document[i].content[len] = '\0';
  }
}

void shift_1(Line *line, int len, int j) {
  for (int i = len - 1; i >= j; --i) {
    line->content[i + 1] = line->content[i];
  }
}

//  3