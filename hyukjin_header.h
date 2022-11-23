#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
#include <stdio.h>

Node* search_tag(int tag);
Node* search_name(char *name); //중복가능해서 그냥 찾으면 출력하는 형식으로 진행함.
Node* search_org(char *org); //중복가능해서 그냥 찾으면 출력하는 형식으로 진행함.