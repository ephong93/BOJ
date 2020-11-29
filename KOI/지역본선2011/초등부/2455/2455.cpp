#include <iostream>

using namespace std;

int main() {
    int a = 0;
    int r = 0;
    for (int i = 0; i < 4; i++) {
        int on, off;
        cin >> off >> on;
        a += (on-off);
        r = max(r, a);
    }
    cout << r << endl;
    return 0;
}