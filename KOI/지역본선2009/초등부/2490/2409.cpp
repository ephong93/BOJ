#include <iostream>

using namespace std;

int main() {

    for (int i = 0; i < 3; i++) {
        int bae = 0, deung = 0;
        for (int j = 0; j < 4; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 0) bae++;
            else deung++;
        }
        if (bae == 1 && deung == 3) cout << "A" << endl;
        else if (bae == 2 && deung == 2) cout << "B" << endl;
        else if (bae == 3 && deung == 1) cout << "C" << endl;
        else if (bae == 4) cout << "D" << endl;
        else cout << "E" << endl;
    }
    return 0;
}