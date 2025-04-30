#include "aryQueue_cnt.h"
#include <iostream>

using namespace std;

int main()
{
    char c;
    Queue < char > q;
    while (1) {
        cin >> c;
        if (c == '.') break; // when '.' entered, leave the loop
        q.enqueue(c);
    }

    while (!q.isEmpty()) {
        cout << "Q: " << q.dequeue() << '\t';
    }
    return 0;
}