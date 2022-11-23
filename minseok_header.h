#ifndef TERM_MINSEOK_HEADER_H
#define TERM_MINSEOK_HEADER_H
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
void read_from_file();
Node * search_menu();
bool main_menu();
void clear_(bool flag);
void get_string(char *str);
#endif //TERM_MINSEOK_HEADER_H
