#include <iostream>

using namespace std;

int N;
int points[4][4];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        points[1][a]++;
        points[2][b]++;
        points[3][c]++;
    }

    int max_sum = 0;
    int max_3=0, max_2=0, max_1=0;
    int max_i = 0;
    bool f = false;
    for (int i = 1; i <= 3; i++) {
        int sum = (points[i][1]+points[i][2]*2+points[i][3]*3);
        if (sum > max_sum) {
            max_sum = sum;
            max_3 = points[i][3];
            max_2 = points[i][2];
            max_1 = points[i][1];
            max_i = i;
            f = true;
        } else if(sum == max_sum) {
            if (points[i][3] > max_3) {
                max_sum = sum;
                max_3 = points[i][3];
                max_2 = points[i][2];
                max_1 = points[i][1];
                max_i = i;
                f = true;
            } else if(points[i][3] == max_3) {
                if (points[i][2] > max_2) {
                    max_sum = sum;
                    max_3 = points[i][3];
                    max_2 = points[i][2];
                    max_1 = points[i][1];
                    max_i = i;
                    f = true;
                } else if(points[i][2] == max_2) {
                    f = false;
                }
            }
        }
    }

    if (f) cout << max_i << " " << max_sum << endl;
    else cout << 0 << " " << max_sum << endl;
    return 0;
}