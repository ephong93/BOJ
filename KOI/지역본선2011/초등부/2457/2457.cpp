#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

vector<pair<int, int>> v;

int convert(int m, int d) {
    int s = 0;
    for (int i = 1; i < m; i++) {
        s += days[i];
    }
    s += d;
    return s;
}

bool compare(pair<int, int> p0, pair<int, int> p1) {
    return p0.first < p1.first;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        int a = convert(m1, d1);
        int b = convert(m2, d2);
        pair<int, int> p;
        p.first = a;
        p.second = b;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), compare);
    int a = convert(3, 1);
    int b = convert(11, 30);
    int r = 0;
    int max_b = a;

    for (auto x : v) {

        if (x.first <= a) {
            max_b = max(max_b, x.second);
            if (max_b > b) {
                r++;
                break;
            }
        } else if (x.first <= max_b) {
            if (x.second <= max_b) {
                continue;
            }
            a = max_b;
            max_b = max(max_b, x.second);
            r++;
            if (max_b > b) {
                r++;
                break;
            }
        } else {
            r = -1;
            break;
        }
    }

    if (max_b <= b) {
        cout << 0 << endl;
    } else {
        cout << r << endl;
    }

    return 0;
}