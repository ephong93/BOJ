#include <iostream>

using namespace std;

int C, R, K;
int arr[1001][1001] = {0,};

int main() {
    cin >> C >> R;
    cin >> K;
    int d = 0;
    int x = 1, y = 1;
    int c = 0;

    int dir_x[4] = {0, 1, 0, -1};
    int dir_y[4] = {1, 0, -1, 0};

    while (true) {
        if (arr[x][y] > 0) break;
        c++;
        arr[x][y] = c;

        if (c == K) break;
        int _x = x+dir_x[d];
        int _y = y+dir_y[d];
        if (_x < 1 || _x > C || _y < 1 || _y > R || arr[_x][_y] > 0) {
            d = (d+1)%4;
            _x = x+dir_x[d];
            _y = y+dir_y[d];
        }
        x = _x;
        y = _y;
    }

    if (c == K) cout << x << " " << y << endl;
    else cout << "0" << endl;
/*
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= R; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
  */  
    return 0;
}