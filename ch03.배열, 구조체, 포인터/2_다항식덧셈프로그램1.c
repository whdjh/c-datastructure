#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_DEGREE 101

typedef struct {
	int degree;					//차수
	float coef[MAX_DEGREE];		//계수
} polynomial;

polynomial poly_add(polynomial A, polynomial B)
{
	polynomial C;						//결과다항식
	int Apos = 0, Bpos = 0, Cpos = 0;	//배열인덱스변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);	//결과다항식차수
	while(Apos <= A.degree && Bpos <= B.degree)
	{
		if(degree_a > degree_b)			//A항 > B항
		{
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if(degree_a == degree_b)	//A항 == B항
		{
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else 							//A항 < B항
		{
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for(int i = p.degree; i > 0; i--)
		printf("3.1dx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}

int main()
{
	polynomial a = {5, {3, 6, 0, 0, 0,10}};
	polynomial b = {4, {7, 0, 5, 0, 1}};
	polynomial c;

	print_poly(a);
	print_poly(b);
	c = poly_add(a, b);
	printf("-------------------------------------------------------------------------------------\n");
	print_poly(c);
	return 0;
}