#include <stdio.h>


int main (void)
{
    int i = 'A';   //same as:   int i = 65;
    printf("The ASCII of \'A\' is 0X%08X = %d \n", i, i );

    int j = '☞';
    printf("The ASCII of \'☞\'  is 0X%08X = %d \n", j, j );
    
    int m = 0X00E2989E;  
    int n = 14850206;  
    printf("The charactor of 0x00E2989E is %c \n", m );
    printf("The charactor of 14850206   is %c \n", n );
    
	typedef struct {
    union {
        float v[3];
        struct {
            float x;
            float y;
            float z;
        };
        struct {
            float azimuth;
            float pitch;
            float roll;
        };
    };
    char status;
    unsigned char reserved[3];
} sensors_vec_t;


    printf("The size of \"sensors_vec_t\" is %ld \n", sizeof(sensors_vec_t));
    printf("The size of \"short\" is %ld \n", sizeof(short));
    printf("The size of \"char\" is %ld \n", sizeof(char));
    printf("The size of \"int\" is %ld \n", sizeof(int));
    printf("The size of \"float\" is %ld \n", sizeof(float));
    printf("The size of \"double\" is %ld \n", sizeof(double));
}
