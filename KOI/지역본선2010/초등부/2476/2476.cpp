#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    int r = 0;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b && b == c) r = max(r, 10000 + a*1000);
        else if (a == b || a == c) r = max(r, 1000+a*100);
        else if (b == c) r = max(r, 1000+b*100);
        else r = max(r, max(a, max(b, c))*100);
    }
    cout << r << endl;
    return 0;
}