#include <iostream>
#include <algorithm>

using namespace std; // 이거 없으면 swap에 빨간 줄 생김.. 왜지????

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


//재귀호출, 함수 길이 매개변수, 교차되면 high와 low 교체, high가
template <typename T, size_t N>
void quicksort(T (&ary)[N], int start, int end)
{
    if(end - start <= 0) return;

    int pivot = start;
    int high = end;
    int low = start + 1;

    cout << endl << "[Partition 전] ";
    printout(ary); //partition 전 출력

    while(low < high){
        while(low < end && ary[pivot] > ary[low]) { // ary[pivot] > ary[low]에 등호 붙어도 됨. 내림차순 정렬할거면 안될 듯.
            low++;
        }
        while(high > 0 && ary[pivot] < ary[high]) { // ary[pivot] < ary[high]에 등호 붙으면 안되는 이유: pivot이 최솟값일 경우 high가 -1까지 작아짐.
            high--;
        }

        if(low >= high) break; // 만약 low, high 위치가 뒤바뀌었으면 그 즉시 break

        swap(ary[low], ary[high]);
    }

    swap(ary[high], ary[pivot]);    

    cout << endl << "[Partition 후] ";
    printout(ary); //partition 후 출력
    cout << endl;
    
    quicksort(ary, start, high - 1);
    quicksort(ary, high + 1, end);

}



int main()
{
    double ary[] = {4.0, 10.4, 9.5, 1.3, 8.5, 5.1, 7.5, 2.1, 3.5, 6.5};
    
    quicksort(ary, 0, 9);

    cout << endl;

    for(int i = 0; i < 10; i++) {
        std::cout << ary[i] << " ";
    }

    return 0;
}

