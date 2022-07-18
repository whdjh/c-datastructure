#include <stdio.h>
#include <stdlib.h>
#include <time.h>   //clock()함수를 사용하기 위한 헤더

int main()
{
    clock_t start, stop;
    double duration;
    start = clock();    //측정시작

    for (int i = 0; i < 100000; i++)    //의미없는 반복 루프
            ;
    stop = clock();     //측정종료
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("수행시간은 %f초 입니다.\n", duration);
    return 0;
}