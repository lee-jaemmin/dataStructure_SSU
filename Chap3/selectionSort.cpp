#include <iostream>

using namespace std;

#include <iostream>

using namespace std;


void selectionSort(int ary[], int length)
{
    for(int i = 0; i < length - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < length; j++) {
            if(ary[j] < ary[minIndex]) {
                minIndex = j;
            }
        }
        int temp = ary[minIndex];
        ary[minIndex] = ary[i];
        ary[i] = temp;
    }
};



int main()
{
    int ary[10] = {10, 7, 2, 3, 9, 4, 6, 5, 8, 1};
    
    
    selectionSort(ary, 10);
    
    
    for(int i = 0; i < 10; i++) {
        cout << ary[i] << " ";
    }
    

    return 0;
}