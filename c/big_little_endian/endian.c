#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int  v=0x12345678;
	char *p = NULL;
	
	p = (char*)&v;
	
	printf("v:%hhx\n", *p);	

	return 0;
}
