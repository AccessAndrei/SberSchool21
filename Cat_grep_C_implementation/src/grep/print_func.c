
#include "print_func.h"

void print_without_name(int size_of_document, Line *document);

void default_print(int size_of_document, Line *document, char **argv,
                   char *filename, int flag_pos, int flag) {
  if (flag_pos != 0) {
    if (strstr(argv[flag_pos], "-c") != NULL) {
      print_with_amount(size_of_document, document, filename, flag);
    } else if (strstr(argv[flag_pos], "-l") != NULL) {
      print_name_of_file_only(size_of_document, document, filename);
    } else if (strstr(argv[flag_pos], "-n") != NULL) {
      print_with_number_of_line(size_of_document, document, filename, flag);
    } else if (strstr(argv[flag_pos], "-h") != NULL) {
      print_without_name(size_of_document, document);
    } else if ((strstr(argv[flag_pos], "-o") != NULL)) {
    } else
      print_with_name_of_file(size_of_document, document, filename, flag);

  } else
    print_with_name_of_file(size_of_document, document, filename, flag);
}

void print_without_name(int size_of_document, Line *document) {
  int index = -1;
  for (int j = 0; j < size_of_document; j++) {
    if (document[j].contains) {
      printf("%s", document[j].content);
      index = j;
    }
  }
  if (index != -1) {
    int len = strlen(document[index].content);
    if (document[index].content[len - 1] != '\n') {
      printf("\n");
    }
  }
  free(document);
}

void print_with_name_of_file(int size_of_document, Line *document,
                             char *filename, int flag) {
  int index = -1;
  if (flag) {
    for (int j = 0; j < size_of_document; j++) {
      if (document[j].contains) {
        printf("%s:%s", filename, document[j].content);
        index = j;
      }
    }

  } else {
    for (int j = 0; j < size_of_document; j++) {
      if (document[j].contains) {
        printf("%s", document[j].content);
        index = j;
      }
    }
  }
  if (index != -1) {
    int len = strlen(document[index].content);
    if (document[index].content[len - 1] != '\n') {
      printf("\n");
    }
  }
  free(document);
}

void print_with_amount(int size_of_document, Line *document, char *filename,
                       int flag) {
  int amount = 0;
  if (flag) {
    for (int j = 0; j < size_of_document; ++j) {
      if (document[j].contains) {
        amount++;
      }
    }
    printf("%s:%d", filename, amount);
  } else {
    for (int j = 0; j < size_of_document; ++j) {
      if (document[j].contains) {
        amount++;
      }
    }
    printf("%d", amount);
  }

  printf("\n");

  free(document);
}

void print_with_number_of_line(int size_of_document, Line *document,
                               char *filename, int flag) {
  int index = -1;
  if (flag) {
    for (int j = 0; j < size_of_document; j++) {
      if (document[j].contains) {
        printf("%s:%d:%s", filename, document[j].line_number,
               document[j].content);
        index = j;
      }
    }
  } else {
    for (int j = 0; j < size_of_document; j++) {
      if (document[j].contains) {
        printf("%d:%s", document[j].line_number, document[j].content);
        index = j;
      }
    }
  }
  if (index != -1) {
    int len = strlen(document[index].content);
    if (document[index].content[len - 1] != '\n') {
      printf("\n");
    }
  }
  free(document);
}

void print_name_of_file_only(int size_of_document, Line *document,
                             char *filename) {
  int flag = 0;
  for (int j = 0; j < size_of_document; j++) {
    if (document[j].contains) {
      flag = 1;
    }
  }
  if (flag) {
    printf("%s\n", filename);
  }

  free(document);
}
