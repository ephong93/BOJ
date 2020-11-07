#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c[3] = {0, 0, 0};
    int f;
    for (int i = 0; i < 3; i++) {
        f = 0;
        int e = 1;
        for (int j = 0; j < 3; j++) {
            int _a = a;
            int _b = b;
            for(int _i = 0; _i < i; _i++) _b /= 10;
            for(int _j = 0; _j < j; _j++) _a /= 10;
            _a = _a % 10;
            _b = _b % 10;

            int _c = _a*_b;
            c[i] += (_c % 10 + f) * e;
            f = _c / 10;
            e *= 10;
        }
        c[i] += f*e;
    }

    cout << c[0] << endl << c[1] << endl << c[2] << endl << c[0]+c[1]*10+c[2]*100;
    return 0;
}