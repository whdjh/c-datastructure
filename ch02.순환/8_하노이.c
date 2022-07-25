#include <stdio.h>

void hanoi(int n, char from, char tmp, char to)
{
	if(n == 1)
		printf("원판 1을 %c에서 %c로 옮긴다.", from, to);
	else
	{
		hanoi(n - 1, from, to, tmp);
		printf("원판 %d를 %c에서 %c로 옮긴다.\n", n, from, tmp);
		hanoi(n - 1, tmp, from, to);
	}
}

int main()
{
	hanoi(4, 'a', 'b', 'c');
	return 0;
}