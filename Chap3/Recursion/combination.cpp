#include <iostream>


//20212861 이재민
int cnt = 0;

using namespace std;

int combination(int n, int k)
{
    if(k == 1) {
        return n;
    }
    else if(n == k) {
        return 1;
    }
    else {
        return (combination(n-1, k-1) + combination(n-1, k));
    }

}


int main()
{
    int n, k;

    cout << "n 입력: ";
    cin >> n;

    cout << "k 입력: ";
    cin >> k;

    int result = combination(n, k);

    cout << "[결과]" << endl;
    cout << result;

    return 0;
}