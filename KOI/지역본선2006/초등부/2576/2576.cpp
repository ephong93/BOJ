#include <iostream>

using namespace std;

int main() {
    int min_odd = -1;
    int total_sum = 0;

    for (int i = 0; i < 7; i++) {
        int tmp_num;
        cin >> tmp_num;
        if (tmp_num % 2 == 0) continue;
        if (min_odd == -1) min_odd = tmp_num;
        else min_odd = min(min_odd, tmp_num);
        total_sum += tmp_num;
    }

    if (total_sum == 0) cout << -1 << endl;
    else {
        cout << total_sum << endl << min_odd << endl;
    }
    return 0;
}