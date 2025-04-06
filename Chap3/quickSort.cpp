#include <iostream>
#include <algorithm>
#include "myCstudent.h"

using namespace std; // �̰� ������ swap�� ���� �� ����.. ����????

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


//���ȣ��, �Լ� ���� �Ű�����, �����Ǹ� high�� low ��ü, high��
template <typename T, size_t N>
void quicksort(T (&ary)[N], int start, int end)
{
    if(end - start <= 0) return;

    int pivot = start;
    int high = end;
    int low = start + 1;

    cout << endl << "[Partition ��] ";
    printout(ary); //partition �� ���

    while(low < high){
        while(low < end && ary[pivot] > ary[low]) { // ary[pivot] > ary[low]�� ��ȣ �پ ��. �������� �����ҰŸ� �ȵ� ��.
            low++;
        }
        while(high > 0 && ary[pivot] < ary[high]) { // ary[pivot] < ary[high]�� ��ȣ ������ �ȵǴ� ����: pivot�� �ּڰ��� ��� high�� -1���� �۾���.
            high--;
        }

        if(low >= high) break; // ���� low, high ��ġ�� �ڹٲ������ �� ��� break

        swap(ary[low], ary[high]);
    }

    swap(ary[high], ary[pivot]);    

    cout << endl << "[Partition ��] ";
    printout(ary); //partition �� ���
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
    
        cout << "[" << i + 1 << "��° �л�]" << endl;
        cout << "�й�: ";
        cin >> id;
        cout << "�̸�: ";
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
