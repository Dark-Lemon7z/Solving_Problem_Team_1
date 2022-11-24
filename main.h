#ifndef MAIN_H
#define MAIN_H
#include <stdbool.h>
#include <stdio.h>

typedef struct data
{
	int tag;
	int year, month, date;
	bool fee_paid; //yes -> 1, no -> 0
	char name[25];
	int age;
	char org[50];
	char job[15];
}Data;

typedef struct node
{
	Data data;
	bool checked;
	struct node * next;
}Node;

typedef struct node_array
{
	Node * node_addr;
	struct node_array * next;
}Node_arr;

struct nodelist
{
	int size;
	Node *head;
}list_info;

#include "hyukjin_header.h"//본인 헤더 파일은 추가
#include "minseok_header.h"
#include "gyeongwon_header.h"
#include "LIM_header.h"
#include "minjun_header.h"
#endif //MAIN_H
