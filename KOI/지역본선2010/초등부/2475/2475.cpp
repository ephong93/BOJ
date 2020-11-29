#include <iostream>

using namespace std;

int main() {
    int r = 0;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        r += a*a;
    }
    r %= 10;
    cout << r << endl;
    return 0;
}