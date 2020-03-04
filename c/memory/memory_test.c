#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	int opt;
	char *string = "m:";
	int   memory_size = 10*1024*1024;
	char *p_m = NULL;
	int i = 0;
	int count=10;

	while((opt=getopt(argc, argv, string)) != -1)
	{
		switch(opt)
		{
			case 'm':
				printf("memory size:%s Mi\n", optarg);
				memory_size = atoi(optarg)*1024*1024;
				break;
			case 'c':
				printf("count:%s Mi\n", optarg);
				count = atoi(optarg);
				break;

			default:
				printf("unkown parm!\n");
				break;
		}
	}

	printf("memory size:%d bytes\n", memory_size);
	printf("counts:%d times\n", count);

	p_m = (char *)malloc(memory_size);	
	if(p_m == NULL)
	{
		printf("malloc memory failed!\n");
		return -1;
	}

	printf("start testing...\n");
	while(count--)	
	{
		for(i=0; i<memory_size; i++)
		{
			p_m[i] = 'a';
		}
		sleep(5);
		printf("...\n");
	}
	
	free(p_m);

	return 0;
}
