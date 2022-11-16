#include "main.h"
/*
 * main.c에는 작성하지 말고 각자 c 파일을 만들어서 업로드
 * 나중에 파일 분리 + 헤더화 하기 위함
 */
int main()
{
	init();
	read_from_file();
	while(main_menu())
	{
		clear_(1);
	}
}
