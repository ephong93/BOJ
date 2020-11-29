#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int r = 0;
    int t = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            if (i < s.size()-1 && s[i+1] == ')') {
                r += t;
                i++;
            } else t++;
        } else if(s[i] == ')') {
            r ++;
            t--;
        }
    }

    cout << r << endl;
    return 0;
}