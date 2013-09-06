#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int random_num(int x){
    int i;
    i = rand();
    return (int)((float) i / RAND_MAX * x);
}

int main(void)
{
	int i;
	unsigned seed = (unsigned)time(NULL);

	printf("The seed is %d. \n", seed);

	srand((unsigned)time(NULL));

	for(i=0 ; i<10; i++)
		printf("%d  ", random_num(100));

	printf("\n");
}
