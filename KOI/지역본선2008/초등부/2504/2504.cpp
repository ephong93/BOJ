#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> stack1;
vector<int> stack2;
string str;


int main() {
    cin >> str;
    bool f = true;
    for (int i = 0; i < str.size(); i++) {
        char c = str.at(i);
        if (c == '(' || c == '[') {
            stack1.push_back(c);
            stack2.push_back(0);
        } else if (c == ')') {
            if (stack1.empty()) {
                f = false;
                break;
            }
            char c_ = stack1.back();
            int t = stack2.back();
            stack1.pop_back();
            stack2.pop_back();
            if (c_ != '(') {
                f = false;
                break;
            }
            if (stack2.empty()) stack2.push_back(max(2, t*2));
            else {
                int _t = stack2.back() + max(2, t*2);
                stack2.pop_back();
                stack2.push_back(_t);
            }
        } else if (c == ']') {
            if (stack1.empty()) {
                f = false;
                break;
            }
            char c_ = stack1.back();
            int t = stack2.back();
            stack1.pop_back();
            stack2.pop_back();
            if (c_ != '[') {
                f = false;
                break;
            }
            if (stack2.empty()) stack2.push_back(max(3, t*3));
            else {
                int _t = stack2.back() + max(3, t*3);
                stack2.pop_back();
                stack2.push_back(_t);
            }
        }
        if (!f) break;
    }

    if (!stack1.empty()) f = false;

    if (f) cout << stack2.back() << endl;
    else cout << 0 << endl;
    return 0;
}