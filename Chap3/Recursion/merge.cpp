#include <iostream>

int* merge(int temp[], int left[], int right[], int leftSize, int rightSize)
{
    int i = 0, j = 0, index = 0;
    
    while(i < leftSize && j < rightSize) { // left, right 배열 내에서 화살표가 있다면~
        if(left[i] < right[j]) {
            temp[index] = left[i];
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
    
    return temp;
}

int* divide(int ary[], int start, int end)
{
    if(end == start) { // 원소가 1개라면 배열 리턴
        int* base = new int[1];
        base[0] = ary[start];
        return base;
    }
    
    int pivot = int((end + start) / 2); // pivot 결정
    int* left = new int[pivot - start + 1]; // 좌측 정렬 결과를 담을 배열 설정
    int* right = new int[end - pivot]; // 우측 결과를 담을 배열 설정
    
    left = divide(ary, start, pivot); // 좌측 분할
    right = divide(ary, pivot + 1, end); // 우측 분할
    
    int* temp = new int[end - start + 1]; // 결과 임시 배열 선언.

    int leftSize = pivot - start + 1; // 왼쪽 배열 사이즈
    int rightSize = end - pivot; // 오른쪽배열 사이즈

    return merge(temp, left, right, leftSize, rightSize); // 원소 하나하나 복사...?
}


int main()
{
    int ary[] = {6, 3, 1, 4, 5};
    
    int* ary2 = divide(ary, 0, 4);

    std::cout << std::endl;

    for(int i = 0; i < 5; i++) {
        std::cout << ary2[i] << " ";
    }

    return 0;

}