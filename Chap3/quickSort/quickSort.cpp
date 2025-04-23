#include <iostream>
#include <algorithm>
#include "myCstudent.h"

using namespace std; // 이거 없으면 swap에 빨간 줄 생김.. 왜지????

template <typename T, size_t N>
void printout(T (&ary)[N])
{
    if(N <= 1) {
        cout << "ID: " << ary[0].getID()
             << ", Name: " << ary[0].getName()
             
             << ", GPA: " << ary[0].getGPA() << endl;
    return;
    }

    for(int i = 0; i < N; i++) {
        cout << "ID: " << ary[i].getID()
             << ", Name: " << ary[i].getName()
             
             << ", GPA: " << ary[i].getGPA() << endl;
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
    myCStudent students[3];

    for (int i = 0; i < 3; i++) {
        int id;
        string name;
        double gpa;
    
        cout << "[" << i + 1 << "번째 학생]" << endl;
        cout << "학번: ";
        cin >> id;
        cout << "이름: ";
        cin >> name;
        cout << "GPA: ";
        cin >> gpa;
    
        students[i].setID(id);
        students[i].setName(name);
        students[i].setGPA(gpa);
    }
    
    quicksort(students, 0, 3);

    cout << endl;

    for (int i = 0; i < 3; i++) {
        cout << "ID: " << students[i].getID()
             << ", Name: " << students[i].getName()
             
             << ", GPA: " << students[i].getGPA() << endl;
    }
    
    return 0;
}
