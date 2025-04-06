#include <iostream>

//자료구조_20212861_이재민

using namespace std;

void selectionSort(int ary[], int length)
{
    for(int i = 0; i < length - 1; i++) {
        int maxIndex = i;
        for(int j = i + 1; j < length; j++) {
            if(ary[j] > ary[maxIndex]) {
                maxIndex = j;
            }
        }
        int temp = ary[maxIndex];
        ary[maxIndex] = ary[i];
        ary[i] = temp;
    }
}




int main()
{
    int ary[10] = {3, 1, 2, 10, 9, 4, 6, 5, 8, 7};
    
    
    selectionSort(ary, 10);
    
    
    for(int i = 0; i < 10; i++) {
        cout << ary[i] << " ";
    }
    

    return 0;
}