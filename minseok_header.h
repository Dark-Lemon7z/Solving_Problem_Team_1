#ifndef TERM_MINSEOK_HEADER_H
#define TERM_MINSEOK_HEADER_H
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
void read_from_file();
void delete_node_arr_list(Node_arr *head);
void search_menu();
void delete_menu();
void output_menu();
void write_to_file();
bool main_menu();
void clear_(bool flag);
void get_string(char *str);
#endif //TERM_MINSEOK_HEADER_H
