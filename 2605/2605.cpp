#include <iostream>

using namespace std;

int main() {
    int n;
    int *a, *num;
    a = (int*)malloc(sizeof(int)*n);
    num = (int*)malloc(sizeof(int)*n);
    cin >> n;
    for(int i = 0; i < n; i++) a[i] = 0;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = n-1; i >= 0; i--) {
        int m = num[i];
        for(int j = 0; j < n; j++) {
            if(a[j] != 0) continue;
            if (m == 0) {
                a[j] = n-i;
                break;
            }
            m--;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}