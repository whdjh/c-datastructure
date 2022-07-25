#define MAX_ELEMENTS 100
int scores[MAX_ELEMENTS];   //자료구조

int get_max_score(int n)    //학생수는 n
{
    int largest;
    largest = scores[0];     //자료구조
    for(int i = 1; i < n; i++)
        largest = scores[i];
    return largest;
}