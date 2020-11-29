#include <iostream>

using namespace std;

int K, N, M;

int main() {
    cin >> K >> N >> M;

    cout << max(0, K*N-M) << endl;
    return 0;
}