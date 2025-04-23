#include <iostream>
using namespace std;

int* merge(int* sortedAry, int leftAry[], int rightAry[], int leftSize, int rightSize)
{
    int i = 0, j = 0, index = 0;
    while(i < leftSize && j < rightSize)
    {
        if(leftAry[i] < rightAry[j]) {
            sortedAry[index] = leftAry[i];
            i++;
        } else if(leftAry[i] > rightAry[j]) {
            sortedAry[index] = rightAry[j];
            j++;
        }
        index++;
    }

    if(i == leftSize) {
        while(j != rightSize) {
            sortedAry[index] = rightAry[j];
            j++;
            index++;
        }
    } else {
        while(i != leftSize) {
            sortedAry[index] = leftAry[i];
            i++;
            index++;
        }
    }
    return sortedAry;
} 

int* divide(int ary[], int start, int end)
{
    if(start >= end) {
        int* base = new int[1];
        base[0] = ary[start];
        return base;
    }

    int pivot = int((end + start) / 2);

    int* leftAry = new int[pivot-start+1];
    int* rightAry = new int[end - pivot];
    
    leftAry = divide(ary, start, pivot);
    rightAry = divide(ary, pivot + 1, end);

    int leftSize = pivot - start + 1; // 왼쪽 배열 사이즈
    int rightSize = end - pivot; // 오른쪽배열 사이즈

    int sortedAry[end - start + 1];
    return merge(sortedAry, leftAry, rightAry, leftSize, rightSize);
    

}


int main()
{
    int ary[5] = {6, 4, 8, 3, 2};
    int* resultAry = divide(ary, 0, 4);

    for(int i = 0; i < 5; i++) {
        cout << resultAry[i] << endl;
    }

    return 0;
}