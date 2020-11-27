#include <iostream>
#include <vector>

using namespace std;

int board[100][100];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (int x = a; x < a+10; x++) {
            for (int y = b; y < b+10; y++) {
                board[x][y] = 1;
            }
        }
    }

    int area = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            area += board[i][j];
        }
    }
    cout << area << endl;
    return 0;
}