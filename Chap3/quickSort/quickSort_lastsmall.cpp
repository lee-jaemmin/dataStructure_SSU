#include <iostream>
#include <algorithm>

using namespace std;



void quicksort(int ary[], int start, int end)
{
    if(start >= end) return;
    
    int pivot = start;
    int i = pivot + 1;
    int lastSmall = pivot;

    while(i <= end) {
        if(ary[i] < ary[pivot]) { // 더 작은 원소를 찾으면
            lastSmall++; // lastSmall 하나 증가. (작은 원소가 앞으로 갈 공간을 만들어준다고 생각)
            swap(ary[lastSmall], ary[i]); // 작은 원소 앞으로 보내기
        } 
        i++;
    }
    
    swap(ary[pivot], ary[lastSmall]);

    quicksort(ary, start, lastSmall-1);
    quicksort(ary, lastSmall+1, end);
    
}





int main()
{
    int ary[] = {6, 3, 1, 4, 5};
    
    quicksort(ary, 0, 4);

    cout << endl;

    for(int i = 0; i < 5; i++) {
        std::cout << ary[i] << " ";
    }

    return 0;
}