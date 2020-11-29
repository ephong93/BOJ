#include <iostream>

using namespace std;

int D, K;

int main() {
    int a0, b0, a1, b1;
    a0 = 1, a1 = 0;
    b0 = 0, b1 = 1;

    cin >> D >> K;
    for (int i = 2; i < D; i++) {
        int a2 = a0+a1;
        int b2 = b0+b1;
        a0 = a1;
        a1 = a2;
        b0 = b1;
        b1 = b2;
    }

    bool end = false;
    for (int a = 1; a <= K; a++) {
        for (int b = 1; a1*a + b1*b <= K; b++) {
            if (a1*a+b1*b == K) {
                cout << a << endl << b << endl;
                end = true;
                break;
            }
        }
        if (end) break;
    }

    return 0;
}