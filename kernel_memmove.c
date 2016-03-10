#include <stdio.h>

void *mymemmove(void *dest, const void *src, size_t count)
{
	char *tmp;
	const char *s;

	if (dest <= src) {
		tmp = dest;
		s = src;
		while (count--)
			*tmp++ = *s++;
	} else {
		tmp = dest;
		tmp += count;
		s = src;
		s += count;
		while (count--)
			*--tmp = *--s;
	}
	return dest;
}

int main()
{
    char a[] = "0123456789";
    char b[20] = {0};

    mymemmove(b, a, sizeof(a)); 
    printf("a[]= %s\n", a);
    printf("b[]= %s\n", b);
}
