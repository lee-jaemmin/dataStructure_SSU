//20212861 이재민

#include <iostream>
#include <string>
#include <cctype>     // for isdigit
#include <stack>    // 라이브러리 가져오기

using namespace std;

int main() {
    cout << "Input RPN Equation:" << endl;

    stack <int> s; //s 소문자 
    double op1, op2;
    char c;

    while ((c = cin.peek()) != '\n') {  // 엔터를 칠 때까지 반복
        if (isdigit(c)) {  // 숫자이면
            cin >> op1;
            s.push(op1); 
        } else {
            cin >> c;  // 연산자 읽기
            op2 = s.top(); s.pop(); // 라이브러리 사용시 top으로 읽어오고 pop으로 지우기
            op1 = s.top(); s.pop(); // 라이브러리에서 pop은 remove의 역할만 하고 때문에!

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

    cout << "Result: " << s.top() << endl;
    return 0;
}
