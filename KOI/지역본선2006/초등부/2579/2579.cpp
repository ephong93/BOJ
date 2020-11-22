#include <iostream>

using namespace std;

int n;
int point[300];
int dp[300];

int compute(int step) {
    if (step == -1) return 0;
    if (step == 0) return point[0];
    if (step == 1) return point[0] + point[1];
    if (dp[step] >= 0) return dp[step];
    dp[step] = max(point[step] + compute(step-2), point[step] + point[step-1] + compute(step-3));
    return dp[step];
}

int main() {    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> point[i];
        dp[i] = -1;
    }

    cout << compute(n-1) << endl;

    return 0;
}