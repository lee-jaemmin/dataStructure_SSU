#include <iostream>

// 자료구조_20212861_이재민

using namespace std;


void insertionSort(int ary[], int length) {
    for(int key = 1; key < length; key++) {
        int keyValue = ary[key];
        int j = key - 1;
        while(j >= 0 && ary[j] > keyValue) {
            ary[j + 1] = ary[j];
            j--;
        }
        ary[j + 1] = keyValue;
    }
}




int main()
{
    int n;
     cout << "n 입력 : ";
    cin >> n;

    int *ary = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> ary[i];
    }

    insertionSort(ary, n);

    for (int i = 0; i < n; i++) {
        cout << ary[i] << " ";
    }

    delete[] ary;

    return 0;
}