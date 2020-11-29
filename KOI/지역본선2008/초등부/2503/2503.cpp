#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> q;
int n;

bool test(int t) {
    for (int i = 0; i < n; i++) {
        int m, s, b;
        m = q.at(i).at(0);
        s = q.at(i).at(1);
        b = q.at(i).at(2);

        int _s = 0, _b = 0;

        int n0[3] = {m%10, (m/10)%10, (m/100)%10};
        int n1[3] = {t%10, (t/10)%10, (t/100)%10};
        
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (n0[j] == n1[k]) {
                    if (j == k) _s++;
                    else _b++;
                }
            }
        }
        if (_s != s || _b != b) return false;
    }
    return true; 
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m, s, b;
        cin >> m >> s >> b;
        vector<int> a;
        a.push_back(m);
        a.push_back(s);
        a.push_back(b);
        q.push_back(a);
    }

    int r = 0;
    for (int i = 111; i <= 999; i++) {
        int _a = (i / 100) % 10, _b = (i / 10) % 10, _c = i % 10;
        if (_a == _b || _a == _c || _b == _c || _a == 0 || _b == 0 || _c == 0) continue;
        if (test(i)) r++;
    }

    cout << r << endl;
    return 0;
}