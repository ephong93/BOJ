#include <iostream>

using namespace std;

int n;
int A[501] = {0, };
int dp[501];
int compute(int a, int m) {
    if (a > 500) return 0;
    if (dp[a] >= 0) return dp[a];
    if (A[a] <= m) return compute(a+1, m);
    cout << a << " " << A[a] << " " << m << endl;
    dp[a] = max(1 + compute(a+1, A[a]), compute(a+1, m));
    return dp[a];
}


int main() {
    cin >> n;
    for (int i = 0; i <= 500; i++) dp[i] = -1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        A[a] = b;
    }
    
    cout << compute(3, 0) << endl;
    return 0;
}