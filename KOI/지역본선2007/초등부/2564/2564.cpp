// 1. 표현 바꾸기
// 2. 앞, 뒤에 있는 경우
// 3. 반대편에 있는 경우
#include <iostream>
#include <vector>


using namespace std;

int w, h;
int n;
vector<pair<int, int>> stores;
int main() {
    cin >> w >> h;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        pair<int, int> p;
        cin >> a >> b;
        if (a == 3) a = 2;
        else if (a == 2) a = 3;
        if (a == 1) b = w - b;
        else if(a == 4) b = h - b;
        p.first = a;
        p.second = b;
        stores.push_back(p);
    }

    int a, b;
    pair<int, int> dg;
    cin >> a >> b;
    if (a == 3) a = 2;
    else if (a == 2) a = 3;
    if (a == 1) b = w - b;
    else if (a == 4) b = h - b;
    dg.first = a;
    dg.second = b;


    int r = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> p = stores.at(i);
        int a, b;
        a = p.first;
        b = p.second;
        if (a == dg.first) { // 같은 면
            int d = abs(b - dg.second);
            r += d;
        } else if (a == dg.first % 4 + 1) { // 뒤
            if (a % 2 == 0) {
                int d = b + (w - dg.second);
                r += d;
            } else {
                int d = b + (h - dg.second);
                r += d;
            }
        } else if (a == (dg.first+2) % 4 + 1) { // 앞
            if (a % 2 == 0) {
                int d = (h-b) + dg.second;
                r += d;
            } else {
                int d = (w-b) + dg.second;
                r += d;
            }
        } else { // 반대 면
            if (a % 2 == 0) {
                int d = w + min(b + (h-dg.second), (h-b) + dg.second);
                r += d;
            } else {
                int d = h + min(b + (w-dg.second), (w-b) + dg.second);
                r += d;
            }
        }   
    }

    cout << r << endl;
    return 0;
}