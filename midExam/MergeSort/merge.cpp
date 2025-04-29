#include <iostream>
int sorted[5];

void merge(int ary[], int start, int pivot, int end)
{
    int i = 0, j = 0, index = 0;
    
    while(i < leftSize && j < rightSize) { // left, right 배열 내에서 화살표가 있다면~
        if(left[i] < right[j]) {
            sorted[index] = left[i];
            i++;
        } else if (left[i] >= right[j]) {
            temp[index] = right[j];
            j++;
        }
        index++;
    } // i, j 중 하나는 반드시 널포인터가 됨.
    
    // 만약 i가 null이었다면
    if(i == leftSize) {
        // j가 null이 될 때까지 temp에 삽입
        while(j < rightSize) {
            temp[index] = right[j];
            j++;
            index++;
        } 
    } else { // j가 null 이었다면 i가 null 될 때까지 삽입
        while(i < leftSize) {
            temp[index] = left[i];
            i++;
            index++;
        }    
    }
}

void divide(int ary[], int start, int end)
{
    if(end == start) return;

    int pivot = int((start + end) / 2);
    
    divide(ary, start, pivot); // 좌측 분할
    divide(ary, pivot + 1, end); // 우측 분할
    
    int leftSize = pivot - start + 1;
    int rightSize = end - pivot;

    merge(ary, start, pivot, end); // 원소 하나하나 복사...?
}


int main()
{
    int ary[] = {6, 3, 1, 4, 5};
    
    divide(ary, 0, 4);

    std::cout << std::endl;

    for(int i = 0; i < 5; i++) {
        std::cout << ary2[i] << " ";
    }

    return 0;

}