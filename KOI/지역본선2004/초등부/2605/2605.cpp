#include <iostream>

using namespace std;

int main() {
    int n;
    int *a, *num;
    cin >> n;
    a = (int*)malloc(sizeof(int)*n);
    num = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) a[i] = 0;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = n-1; i >= 0; i--) {
        int m = num[i];
        for(int j = n-1; j >= 0; j--) {
            if(a[j] != 0 || a[j] > i+1) continue;
            if (m == 0) {
                a[j] = i+1;
                break;
            }
            m--;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    free(a);
    free(num);
    return 0;
}