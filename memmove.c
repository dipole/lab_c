#include <stdio.h>

void* mymemmove(void* dest, void* source, int count)
{
    void* ret = dest;

    if (dest >= (source + count) || dest <= source)
    {
        while (count--)
          *(char*)dest++ = *(char*)source++;
          // *dest++ = *source++;
    }
    else
    {
        dest = dest + count -1;
        source = source + count -1;
        
        while (count--)
            *(char*)dest-- = *(char*)source--;
    }

    return ret;
}

int main()
{
    char a[] = "0123456789";
    char b[50] = {0};

    mymemmove(b, a, sizeof(a));
    mymemmove(a+5, a+1, 3);

    printf("b[50] = %s \n", b);
    printf("a[] = %s \n", a);
}
