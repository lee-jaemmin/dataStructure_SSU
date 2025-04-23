#include <iostream>

int cnt = 0;


int combination(int n, int k) {
    cnt++;
    if(k == 1) {
        return n;
    }
    else if(k == n) {
        return 1;
    }
    else return combination(n-1, k-1) + combination(n-1, k);
}



int main()
{
    int n;
    std::cout << "n ; ";
    std::cin >> n;

    int k;
    std::cout << "k ; ";
    std::cin >> k;

    std::cout << n <<  "C" << k << "is" << combination(n, k) << std::endl;
    std::cout << "Recursion: " << cnt << std::endl;
    
    

    return 0;
}