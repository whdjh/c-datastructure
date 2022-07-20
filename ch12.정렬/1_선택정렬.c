/*정렬은 정렬할 대상을 레코드라하고 레코드를 필드단위로 나누어진다. 왼쪽리스트와 오른쪽리스트가 있으며 왼쪽에는 정렬되어있고 오른쪽에는 정렬되지않았다고한다. 초기상태에는 왼쪽 리스트는
비어있고 오른쪽은 정렬해야할 숫자가 들어있다.*/
#include <stdio.h>
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) ) //swap 매크로

void selection_sort(int list[], int n)
{
	int least, temp;
	for(int i = 0; i < n - 1; i++)
	{
		least = i;
		for(int j = i + 1; j < n; j++)	//최솟값탐색
		{
			if(list[j] < list[least])
				least = j;
			SWAP(list[i], list[least], temp);
		}
	}
}