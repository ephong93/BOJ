#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int r = 0;
    for (int i = 0; i < 5; i++) {
        int t;
        cin >> t;
        if (t == n) r++;
    }
    cout << r << endl;
    return 0;
}