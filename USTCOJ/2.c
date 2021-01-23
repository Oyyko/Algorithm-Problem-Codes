#include<stdio.h>
#include<stdlib.h>

int main()
{
	char* concent=(char*)malloc(sizeof(char)*(1<<20));
	while(gets(concent))
		puts(concent);
}
