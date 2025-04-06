#include <iostream>
#include "Student.h"
using namespace std;


void swapElements(Student a[], int first, int last) {
    Student temp = a[first];
    a[first] = a[last];
    a[last] = temp;
}

int partition(Student a[], int first, int last) {
    int lastSmall = first;
    Student temp;

    for (int i = first + 1; i <= last; i++) {
        if (a[i] <= a[first]) {
            ++lastSmall;
            swapElements(a, lastSmall, i);
        }
    }


    swapElements(a, first, lastSmall);


    return lastSmall;
}

void quicksort(Student a[], int first, int last) {
    if (first >= last) {
        return;
    }

    int split = partition(a, first, last);
    quicksort(a, first, split - 1);
    quicksort(a, split + 1, last);
}

int main() {
    const int SIZE = 5;
    Student students[SIZE];
    int score;
    string name;

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << "번 학생 이름과 점수 입력 (Ex. 홍길동 점수): ";
        cin >> name >> score;
        students[i] = Student(score, name);
    }

    cout << endl << "정렬 전 LIST : " << endl; // 정렬 전 이름, 점수 출력
    for (int i = 0; i < 5; i++)
    {
        cout << students[i].GetName()  << " : " << students[i].GetScore() << endl;
    }

    quicksort(students, 0, 4); // 점수 순으로 정렬

    cout << endl << "정렬 후 LIST : " << endl; // 정렬 후 이름, 점수 출력
    for (int i = 0; i < 5; i++)
    {
        cout << students[i].GetName() << " : " << students[i].GetScore() << endl;
    }

    return 0;
}

bool operator <=(Student& s1, Student& s2)
{
    return (s1.GetScore() <= s2.GetScore());
}
bool operator >=(Student& s1, Student& s2)
{
    return (s1.GetScore() <= s2.GetScore());
}