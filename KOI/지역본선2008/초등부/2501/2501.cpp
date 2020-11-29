#include <iostream>

using namespace std;

int N, K;

int main() {
    cin >> N >> K;    
    int k = 0;
    int i = 1;
    while (i <= N) {
        if (N % i == 0) {
            k++;
            if (k == K) break;
        }
        i++;
    }

    if (k < K) cout << 0 << endl;
    else cout << i << endl;
    return 0;
}