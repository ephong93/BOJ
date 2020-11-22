#include <iostream>

using namespace std;

int main() {
    int count[10] = {0,};
    int A, B, C, D;
    cin >> A >> B >> C;
    D = A*B*C;
    while (D > 0) {
        int a = D % 10;
        count[a]++;
        D /= 10;
    }
    for (int i = 0; i < 10; i++) {
        cout << count[i] << endl;
    }
    return 0;
}