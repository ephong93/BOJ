#include <iostream>

using namespace std;

int main() {
    int max_v = 0, max_i = -1;
    for (int i = 0; i < 9; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > max_v) {
            max_v = tmp;
            max_i = i+1;
        }
    }

    cout << max_v << endl << max_i;
    return 0;
}