#include <iostream>
using namespace std;
string s;
int main() {
    cin >> s;
    int r = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i == 0) r += 10;
        else if(s[i-1] == '(' && s[i] == '(') r += 5;
        else if(s[i-1] == '(' && s[i] == ')') r += 10;
        else if(s[i-1] == ')' && s[i] == '(') r += 10;
        else if(s[i-1] == ')' && s[i] == ')') r += 5;
    }

    cout << r << endl;
    return 0;
}