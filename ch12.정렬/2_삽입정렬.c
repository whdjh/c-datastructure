void insertion_sort(int list[], int n)
{
    int key;
    for(int i = 1; i < n; i++)                              //인덱스는 이미 정렬 된것이라고 볼 수 있으므로 인덱스를 1부터 시작시킴
    {
        int j;
        key = list[i];                                      //현재 삽입될 숫자를 key에 넣어준다.
        for(int j = i - 1; j >= 0 && list[j] > key; j--)    //현재 정렬된 배열은 i - 1 까지 이므로 i - 1부터 역순으로 조사시킴
            list[j + 1] = list[j];                          //j값이 음수가 아니며 key값보다 정렬된 배열의 값이 크면 j를 j + 1로 이동시켜줌
        list[j + 1] = key;                                  //j 정수가 key보다 작으므로 j + 1번째는 key값이 들어갈 위치다.
    }
}