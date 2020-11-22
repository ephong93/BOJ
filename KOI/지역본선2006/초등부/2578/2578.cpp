#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows[5] = {0,};
    int cols[5] = {0,};
    int tr[2] = {0,};
    pair<int, int> coords[26];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int n;
            cin >> n;
            coords[n].first = i;
            coords[n].second = j;
        }
    }

    //cout << "Print rows: " << endl;
    //for(int i = 0; i < 5; i++) cout << rows[i] << " ";
    //cout << "---------------" << endl;
    int c = 0;
    int r = -1;
    int count_steps = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int n, x, y;
            count_steps++;
            cin >> n;
            y = coords[n].first;
            x = coords[n].second;
            rows[y]++;
            if (rows[y] == 5) c++;
            cols[x]++;
            if (cols[x] == 5) c++;
            if (x == y) {
                tr[0]++;
                if (tr[0] == 5) c++;
            }
            if(x+y == 4) {
                tr[1]++;
                if (tr[1] == 5) c++;
            }
            
            if (c >= 3 && r == -1) r = count_steps;
            // cout << "coords: " << y << ", " << x << "tr: " << tr[0] << ", " << tr[1] << ", c: " << c << ", count_steps: " << count_steps << endl;
        }
    }


    cout << r << endl;
    return 0;
}