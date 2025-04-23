#include <algorithm>
#include <iostream>

//20212861 이재민

using namespace std; 

template <typename T, size_t N>
void printout(T (&ary)[N])
{
    if(N <= 1) {
        cout << ary[0];
    return;
    }

    for(int i = 0; i < N; i++) {
        cout << ary[i] << " ";
    }
}


template <class ListType>
int partition(ListType (&ary), int start, int end)
{
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
    cout << endl << "[Partition 후]" << endl;
    printout(ary);

    return lastSmall;
}

template <class ListType>
void quicksort(ListType (&ary), int start, int end)
{
    if(start >= end) return;

    cout << endl << "[Partition 전]" << endl;
    printout(ary);

    int split = partition(ary, start, end);

    cout << endl << "[Partition 후]" << endl;
    printout(ary);

    quicksort(ary, start, split-1);
    quicksort(ary, split+1, end);
    
}




int main()
{
    double ary[] = {6.4, 3.1, 1.5, 4.6, 5.9};
    
    quicksort(ary, 0, 4);

    cout << endl;

    for(int i = 0; i < 5; i++) {
        std::cout << ary[i] << " ";
    }

    return 0;
}

