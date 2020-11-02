#include <iostream>
#include <string>

using namespace std;


int main() {
    int n;
    int r = 0;
    cin >> n;

    int hist[30] = {0,};

    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
        hist[s[j]-'A']++;
    }

    for(int i = 1; i < n; i++) {
        string s;
        int _hist[30] = {0,};
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            _hist[s[j]-'A']++;
        }

        int a = 0, b = 0;
        bool valid = true;
        for (int j = 0; j < 30; j++) {
            if (hist[j] == _hist[j]) continue;
            else if (hist[j] - _hist[j] == 1) a++;
            else if (hist[j] - _hist[j] == -1) b++;
            else {
                valid = false;
                break;
            }
        }
        if (valid && (a+b <= 1 || (a == 1 && b == 1))) r++;
    }
    cout << r;

}