//20212861 이재민

#include <iostream>
#include <string>
#include <cctype>     // isdigit
#include "stack.h"    // 사용자 정의 스택 헤더

using namespace std;

int main() {
    cout << "Input RPN Equation:" << endl;

    Stack<double> s;
    double op1, op2;
    char c;

    while ((c = cin.peek()) != '\n') {  // 엔터를 칠 때까지 반복
        if (isdigit(c)) {  // 숫자이면
            cin >> op1;
            s.push(op1);
        } else {
            cin >> c;  // 연산자 읽기
            op2 = s.pop();
            op1 = s.pop();

            switch (c) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/':
                    if (op2 == 0) {
                        cerr << "Division by zero!\n";
                        return 1;
                    } else {
                        s.push(op1 / op2);
                    }
                    break;
                default:
                    cerr << "Unknown operator: " << c << endl;
                    return 1;
            }
        }

        // 공백 건너뛰기
        while ((c = cin.peek()) == ' ') {
            cin.ignore(1, ' ');
        }
    }

    cout << "Result: " << s.pop() << endl;
    return 0;
}
