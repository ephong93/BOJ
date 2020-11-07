#include <iostream>

using namespace std;

int nums[40];
int mem[40] = {0,};
int n;

int compute(int a) {
    if (a == n) return 1;
    if (a > n) return 0;
    if (mem[a] >= 0) return mem[a];
    if (nums[a] == 0) {
        mem[a] = 0;
    } else {
        int n = 10*nums[a] + nums[a+1];
        if (n >= 10 && n <= 34) mem[a] = compute(a+1)+compute(a+2);
        else mem[a] = compute(a+1);
    }
    return mem[a];
}

int main() {
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        nums[i] = a[i] - '0';
        mem[i] = -1;
    }
    n = a.size();

    cout << compute(0);
    return 0;
}