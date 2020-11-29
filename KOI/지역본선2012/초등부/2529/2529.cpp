#include <iostream>
#include <vector>

using namespace std;

int k;
char ineqs[10];
vector<int> stack;
bool used[10] = {false};
long long max_r = 0;
long long min_r = 9999999999;
char max_r_s[10], min_r_s[10];

void find() {
    if (stack.size() == k+1) {
        long long v = 0;
        long long e = 1;
        char s[10];
        for (int i = 0; i < stack.size(); i++) {
            v += stack[stack.size()-i-1]*e;
            e *= 10;
            s[i] = '0'+stack[stack.size()-i-1];
        }
        if (v > max_r) {
            max_r = v;
            for (int i = 0; i < k+1; i++) max_r_s[i] = s[i];
        }
        if (v < min_r) {
            min_r = v;
            for (int i = 0; i < k+1; i++) min_r_s[i] = s[i];
        }
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (used[i]) continue;
        if (!stack.empty()) {
            char c = ineqs[stack.size()-1];
            int a = stack.back();
            int b = i;
            if (c == '<' && a >= b) continue;
            else if(c == '>' && a <= b) continue;
        }
        used[i] = true;
        stack.push_back(i);
        find();
        used[i] = false;
        stack.pop_back();
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> ineqs[i];
    }

    find();

    for (int i = k; i >= 0; i--) cout << max_r_s[i];
    cout << endl;
    for (int i = k; i >= 0; i--) cout << min_r_s[i];
    cout << endl;
    return 0;
}