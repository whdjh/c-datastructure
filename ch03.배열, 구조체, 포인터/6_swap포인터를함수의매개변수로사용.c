#include <stdio.h>

void swap(int *px, int *py)
{
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}

int main()
{
	int a = 1, b = 2;
	printf("호출전: a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("호출후: a = %d, b = %d\n", a, b);
	return 0;
}