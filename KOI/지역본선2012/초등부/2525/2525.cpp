#include <iostream>

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b;
    cin >> c;

    b += c;
    while(b >= 60) {
        b -= 60;
        a++;
        if (a >= 24) a = 0;
    }

    cout << a << " " << b << endl;
    return 0;
}