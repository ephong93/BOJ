#include <iostream>

using namespace std;
int N;
int arr[1000001] = {0,};
int main() {
    cin >> N;
    int r = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp] = arr[tmp-1]+1;
        r = max(r, arr[tmp]);
    }

    cout << N-r << endl;

    return 0;
}