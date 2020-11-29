#include <iostream>
#include <vector>

using namespace std;

int n;
int tmp_arr[10001];
int arr[10001];
vector<pair<int, int>> seg;

void reverse(int i) {
    for (int j = 1; j <= n; j++) {
        if (arr[j] == i) {
            //cout << i << " " << j << " " << min(i, j) << " " << (min(i, j) + max(i, j)) / 2;
            for (int k = min(i, j); k <= (min(i, j) + max(i, j)) / 2; k++) {
                int tmp = arr[k];
                arr[k] = arr[min(i,j)+max(i,j)-k];
                arr[min(i,j)+max(i,j)-k] = tmp;
            }
            pair<int, int> p;
            p.first = min(i, j);
            p.second = max(i, j);
            seg.push_back(p);
            break;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        tmp_arr[i] = arr[i];
    }

    int c = 2;
    bool success = true;
    for (int i = 1; i <= n; i++) {
        if (arr[i] != i) {
            if (c > 0) {
                reverse(i);
                c--;
            } else {
                success = false;
                break;
            }
        }
        if (!success) break;
    }

    if (success) {
        for (int i = 0; i < 2-c; i++) {
            cout << seg.at(i).first << " " << seg.at(i).second << endl;
        }
        for (int i = 0; i < c; i++) {
            cout << "1 1" << endl;
        }
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        arr[i] = tmp_arr[i];
    }
    c = 2;
    success = true;
    while (!seg.empty()) seg.pop_back();
    for (int i = n; i >= 1; i--) {
        if (arr[i] != i) {
            if (c > 0) {
                reverse(i);
                c--;
            } else {
                success = false;
                cout << i << endl;
                break;
            }
        }
        if (!success) break;
    }

    if (success) {
        for (int i = 0; i < 2-c; i++) {
            cout << seg.at(i).first << " " << seg.at(i).second << endl;
        }
        for (int i = 0; i < c; i++) {
            cout << "1 1" << endl;
        }
        return 0;
    }
    
    return 0;
}