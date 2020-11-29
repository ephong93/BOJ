#include <iostream>
#include <vector>

using namespace std;

int K;
vector<vector<int>> v;
int main() {
    cin >> K;
    int arr[6];
    for (int i = 0; i < 6; i++) {
        int a, b;
        cin >> a;
        cin >> arr[i];
    }

    int max_area = 0;
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        max_area = max(max_area, arr[i % 6] * arr[(i+1) % 6]);
        sum += arr[i%6] * arr[(i+1)%6];
    }

    cout << K * (max_area-(max_area*3 - sum)) << endl;
    return 0;
}