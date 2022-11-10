#ifndef MAIN_H
#define MAIN_H
#include <stdbool.h>
#include <stdio.h>
#include "minseok_header.h"//본인 헤더 파일은 추가
/*
 * 이곳에 본인이 작성한 헤더를 연결시킬 것임
 * 여기다가 작성하지 말고 본인 헤더에다가 작성
 */
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
	struct node * next;
}Node;

struct nodelist
{
	int size;
	Node *head;
}list_info;

#endif //MAIN_H
