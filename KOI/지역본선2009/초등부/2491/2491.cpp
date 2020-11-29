#include <iostream>

using namespace std;

int N;
int arr[100000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int r = 1;
    int tmp = 1;
    for (int i = 0; i < N-1; i++) {
        if (arr[i] <= arr[i+1]) {
            tmp++;
            r = max(r, tmp);
        } else {
            tmp = 1;
        }
    }

    tmp = 1;
    for (int i = 0; i < N-1; i++) {
        if (arr[i] >= arr[i+1]) {
            tmp++;
            r = max(r, tmp);
        } else {
            tmp = 1;
        }
    }

    cout << r << endl;
    return 0;
}