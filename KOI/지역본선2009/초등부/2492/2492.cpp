#include <iostream>
#include <vector>


using namespace std;

int N, M, T, K;

vector<pair<int, int>> stones;

int count(int x0, int x1, int y0, int y1) {
    int r = 0;
    for (int i = 0; i < T; i++) {
        pair<int, int> p = stones.at(i);
        if (p.first >= x0 && p.first <= x1 &&
            p.second >= y0 && p.second <= y1) {
                r++;
            }
    }
    return r;
}

int main() {
    cin >> N >> M >> T >> K;

    for (int i = 0; i < T; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        stones.push_back(p);
    }


    int r = 0;
    int r_x = 0;
    int r_y = 0;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            pair<int, int> p1 = stones.at(i);
            pair<int, int> p2 = stones.at(j);

            int x = p1.first;
            int y = p2.second;
            
            if (x + K <= N && y + K <= M) {
                int tmp = count(x, x+K, y, y+K);
                if (tmp > r) {
                    r = tmp;
                    r_x = x;
                    r_y = y+K;
                }
            }

            if (x - K >= 0 && y - K >= 0) {
                int tmp = count(x-K, x, y-K, y);
                if (tmp > r) {
                    r = tmp;
                    r_x = x-K;
                    r_y = y;
                }
            }
        }
    }

    cout << r_x << " " << r_y << endl;
    cout << r << endl;
    return 0;
}