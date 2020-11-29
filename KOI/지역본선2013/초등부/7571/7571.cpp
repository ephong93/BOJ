#include <iostream>

using namespace std;

int M, N;
int rows[10001] = {0,};
int cols[10001] = {0,};

int main() {
    cin >> N >> M;

    int r_d = 0;
    int c_d = 0;
    int left = 0;
    int up = 0;
    for (int i = 0; i < M; i++) {
        int r, c;
        cin >> r >> c;
        r_d += r-1;
        c_d += c-1;
        rows[r]++;
        cols[c]++;

        if (r == 1) left++;
        if (c == 1) up++;
    }
    
    int min_r = r_d;
    int min_c = c_d;
    for (int i = 2; i <= N; i++) {
        r_d += left;
        r_d -= (M-left);
        c_d += up;
        c_d -= (M-up);

        left += rows[i];
        up += cols[i];
        min_r = min(min_r, r_d);
        min_c = min(min_c, c_d);
    }

    cout << min_r+min_c << endl;

    return 0;
}