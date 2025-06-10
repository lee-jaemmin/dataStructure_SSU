#include "myStudent.h"
#include "LinkedQueue.h"
#include <iostream>
//20212861 이재민   
using namespace std;

int main()
{
    
    LinkedQueue <CStudent> q;
    int n;

    while (1) {
        CStudent student;
        cin >> n;
        student.SetID(n);

        if (n == 0) break; // when '.' entered, leave the loop
        q.enqueue(student);
    }

    while (!q.isEmpty()) {
        CStudent student = q.dequeue();
        cout << "Q: " << student.GetID() << '\t';
    }
    return 0;

}