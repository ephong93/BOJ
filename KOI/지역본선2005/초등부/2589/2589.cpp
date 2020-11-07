#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int h, w;
bool map[50][50] = {false};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int bfs(int y, int x, bool visited[][50]) {
    int d = 0;
    queue<pair<int, int>> q;
    pair<int, int> p;
    p.first = y;
    p.second = x;
    visited[y][x] = true;
    q.push(p);
    while (q.size() > 0) {
        int s = q.size();
        for(int i = 0; i < s; i++) {
            pair<int, int> c = q.front();
            int y = c.first;
            int x = c.second;
            q.pop();
            for(int j = 0; j < 4; j++) {
                int _x = x + dx[j];
                int _y = y + dy[j];
                if (_x >= w || _x < 0 || _y >= h || _y < 0) continue;
                if (!map[_y][_x]) continue;
                if (visited[_y][_x]) continue;
                visited[_y][_x] = true;
                pair<int, int> p;
                p.first = _y;
                p.second = _x;
                q.push(p);
            }
        }
        d++;
    }
    return d;
}

int find(int y, int x) {
    bool visited[50][50] = {false,};
    int d = bfs(y, x, visited);
    return d;
}

int main() {
    cin >> h >> w;
    for (int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            char c;
            cin >> c;
            if (c == 'W') map[i][j] = false;
            else map[i][j] = true;
        }
    }
    
    int d = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!map[i][j]) continue;
            d = max(d, find(i, j));
        }
    }
    
    cout << d-1;
    return 0;
}
