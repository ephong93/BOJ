#include <iostream>

using namespace std;

int w, h;
int p, q;
int t;

int main() {
    cin >> w >> h;
    cin >> p >> q;
    cin >> t;

    int x = p+t;
    int y = q+t;
    if ((x / w) % 2 == 0) x = x % w;
    else x = w - (x % w);
    if ((y / h) % 2 == 0) y = y % h;
    else y = h - y % h;

    cout << x << " " << y << endl;
    return 0;
}