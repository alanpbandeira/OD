#include <stdio.h>

int main(int argc, char const *argv[])
{
	int b[10] = {2,3,14,65,6,55,54,1,98,44};
	int a[10];
	int i, c;
	for (i = 0; i < 10; ++i)
	{
		c = (int)((float)10 * ((float)b[i] / 100.0));
		a[c] = b[i];
		printf("%d\n", c);
	}

	printf("\n");

	for (i=0; i < 10; ++i)
	{
		printf("%d\n", a[i]);
	}

	return 0;
}