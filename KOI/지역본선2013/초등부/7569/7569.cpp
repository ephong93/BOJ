#include <iostream>
#include <queue>

using namespace std;
int M, N, H;
int arr[100][100][100];
queue<vector<int>> q;
int r = 0;

void search_neighbors(int h, int n, int m) {
    int dirs_h[6] = {1, -1, 0, 0, 0, 0};
    int dirs_m[6] = {0, 0, 1, -1, 0, 0};
    int dirs_n[6] = {0, 0, 0, 0, 1, -1};

    for (int i = 0; i < 6; i++) {
        int _h = h + dirs_h[i];
        int _m = m + dirs_m[i];
        int _n = n + dirs_n[i];
        if (_h < 0 || _h >= H) continue;
        if (_m < 0 || _m >= M) continue;
        if (_n < 0 || _n >= N) continue;
        if (arr[_h][_n][_m] == 0) {
            vector<int> v;
            v.push_back(_h);
            v.push_back(_n);
            v.push_back(_m);
            q.push(v);
            arr[_h][_n][_m] = 1;
        }
    }
}   

void bfs() {
    while (true) {
        int s = q.size();
        for (int i = 0; i < s; i++) {
            vector<int> v = q.front();
            q.pop();
            int h = v[0], n = v[1], m = v[2];
            search_neighbors(h, n, m); 
        }
        if (q.empty()) break;
        r++;
    }
}


int main() {
    cin >> M >> N >> H;

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> arr[h][n][m];
                if (arr[h][n][m] == 1) {
                    vector<int> v;
                    v.push_back(h);
                    v.push_back(n);
                    v.push_back(m);
                    q.push(v);
                }
            }
        }
    }

    bfs();

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (arr[h][n][m] == 0) {
                    r = -1;
                    break;
                }
            }
            if (r == -1) break;
        }
        if (r == -1) break;
    }
    cout << r << endl;

    return 0;
}