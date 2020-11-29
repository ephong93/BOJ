#include <iostream>
#include <vector>


using namespace std;

// 1. 다른 사각형에 포함된 corner를 찾는다.
// 2. cross되는 점들을 찾는다.
// 3. 찾아진 점들의 갯수로 판별

vector<pair<int, int>> find_corners(int r1[4], int r2[4]) {
    vector<pair<int, int>> r;
    for (int i = 0; i < 4; i++) {
        pair<int, int> p = make_pair(r1[i/2*2], r1[1+(i%2)*2]);
        if (p.first >= r2[0] && p.first <= r2[2] && p.second >= r2[1] && p.second <= r2[3]) {
            r.push_back(p);
        }
    }

    for (int i = 0; i < 4; i++) {
        pair<int, int> p = make_pair(r2[i/2*2], r2[1+(i%2)*2]);
        if (p.first >= r1[0] && p.first <= r1[2] && p.second >= r1[1] && p.second <= r1[3]) {
            r.push_back(p);
        }
    }
    return r;
}


vector<pair<int, int>> find_cross(int r1[4], int r2[4]) {
    int next[4] = {1, 3, 0, 2};
    vector<pair<int, int>> r;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            pair<int, int> p0 = make_pair(r1[i/2*2], r1[1+(i%2)*2]);
            int _i = next[i];
            pair<int, int> p1 = make_pair(r1[_i/2*2], r1[1+(_i%2)*2]);

            int _j = next[j];
            pair<int, int> p2 = make_pair(r2[j/2*2], r2[1+(j%2)*2]);
            pair<int, int> p3 = make_pair(r2[_j/2*2], r2[1+(_j%2)*2]);

            //cout << p0.first << " " << p0.second << " " << p1.first << " " << p1.second << endl;
            //cout << p2.first << " " << p2.second << " " << p3.first << " " << p3.second << endl;

            // 선으로 겹치는 경우
            if (p0.first == p1.first && p2.first == p3.first && p0.first == p2.first) {
                if (min(p2.second, p3.second) <= p0.second && p0.second <= max(p2.second, p3.second)) {
                    r.push_back(make_pair(p0.first, p0.second));
                }
                if(min(p2.second, p3.second) <= p1.second && p1.second <= min(p2.second, p3.second)) {
                    r.push_back(make_pair(p0.first, p1.second));
                }
                if (min(p0.second, p1.second) <= p2.second && p2.second <= max(p0.second, p1.second)) {
                    r.push_back(make_pair(p0.first, p2.second));
                }
                if (min(p0.second, p1.second) <= p3.second && p3.second <= max(p0.second, p1.second)) {
                    r.push_back(make_pair(p0.first, p3.second));
                }
            } else if(p0.second == p1.second && p2.second == p3.second && p0.second == p2.second) {
                if (min(p2.first, p3.first) <= p0.first && p0.first <= max(p2.first, p3.first)) {
                    r.push_back(make_pair(p0.first, p0.second));
                }
                if(min(p2.first, p3.first) <= p1.first && p1.first <= min(p2.first, p3.first)) {
                    r.push_back(make_pair(p1.first, p0.second));
                }
                if (min(p0.first, p1.first) <= p2.first && p2.first <= max(p0.first, p1.first)) {
                    r.push_back(make_pair(p2.first, p0.second));
                }
                if (min(p0.first, p1.first) <= p3.first && p3.first <= max(p0.first, p1.first)) {
                    r.push_back(make_pair(p3.first, p0.second));
                }
            } else if (p0.first == p1.first) {    // 점으로 겹치는 경우
                if (min(p2.first, p3.first) <= p0.first && p0.first <= max(p2.first, p3.first) &&
                    min(p0.second, p1.second) <= p2.second && p2.second <= max(p0.second, p1.second)) {
                        r.push_back(make_pair(p0.first, p2.second));
                    }
            } else if (p0.second == p1.second) {
                if (min(p0.first, p1.first) <= p2.first && p2.first <= max(p0.first, p1.first) &&
                    min(p2.second, p3.second) <= p0.second && p0.second <= max(p2.second, p3.second)) {
                        r.push_back(make_pair(p2.first, p0.second));
                    }
            }
        }
    }
    return r;
}



int main() {
    for (int i = 0; i < 4; i++) {
        int r1[4];
        int r2[4];

        cin >> r1[0] >> r1[1] >> r1[2] >> r1[3];
        cin >> r2[0] >> r2[1] >> r2[2] >> r2[3];

        vector<pair<int, int>> corners = find_corners(r1, r2);
        vector<pair<int, int>> cross = find_cross(r1, r2);
        for (int i = 0; i < cross.size(); i++) corners.push_back(cross[i]);

        vector<pair<int, int>> r;
        for (int i = 0; i < corners.size(); i++) {
            if (r.empty()) {
                r.push_back(corners[i]);
                continue;
            }
            bool f = true;
            for (int j = 0; j < r.size(); j++) {
                if (r[j].first == corners[i].first && r[j].second == corners[i].second) {
                    f = false;
                    break;
                }
            }
            if (f) r.push_back(corners[i]);
        }

        if (r.size() == 0) cout << "d" << endl;
        else if (r.size() == 1) cout << "c" << endl;
        else if (r.size() == 2) cout << "b" << endl;
        else cout << "a" << endl;
    }
    return 0;
}