#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[51][2];

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        arr[i][0] = a;
        arr[i][1] = b;
    }

    for (int i = 1; i <= N; i++) {
        int r = 1;
        for (int j = 1; j <= N; j++) {
            if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) r++;
        }
        cout << r << " ";
    }
    cout << endl;
    return 0;
}