#include <iostream>
#include <string>

using namespace std;

int to_num(string s) {
    if (s.size() == 1) {
        char c = s[0];
        switch(c) {
            case 'I':
            return 1;
            case 'V':
            return 5;
            case 'X':
            return 10;
            case 'L':
            return 50;
            case 'C':
            return 100;
            case 'D':
            return 500;
            case 'M':
            return 1000;
        }
    } else if (s.size() == 2) {
        int a = to_num(s.substr(0, 1));
        int b = to_num(s.substr(1, 1));
        if (a < b) return b-a;
        else return a+b;
    }
    int n = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i == s.size()-1) n += to_num(s.substr(i, 1));
        else {
            int a = to_num(s.substr(i, 1));
            int b = to_num(s.substr(i+1, 1));
            
            if (a < b) {
                n -= a;
            } else {
                n += a;
            }
        }
        
    }
    return n;
}

string to_sym(int n) {
    int c;
    string sym = "";
    while (n >= 1000) {
        sym.push_back('M');
        n -= 1000;
    }
    if (n >= 900) {
        sym.push_back('C');
        sym.push_back('M');
        n -= 900;
    }
    if (n >= 500) {
        sym.push_back('D');
        n -= 500;
    }
    if (n >= 400) {
        sym.push_back('C');
        sym.push_back('D');
        n -= 400;
    }
    while (n >= 100) {
        sym.push_back('C');
        n -= 100;
    }
    if (n >= 90) {
        sym.push_back('X');
        sym.push_back('C');
        n -= 90;
    }
    if (n >= 50) {
        sym.push_back('L');
        n -= 50;
    }
    if (n >= 40) {
        sym.push_back('X');
        sym.push_back('L');
        n -= 40;
    }
    while (n >= 10) {
        sym.push_back('X');
        n -= 10;
    }
    if (n >= 9) {
        sym.push_back('I');
        sym.push_back('X');
        n -= 9;
    }
    if (n >= 5) {
        sym.push_back('V');
        n -= 5;
    }
    if (n >= 4) {
        sym.push_back('I');
        sym.push_back('V');
        n -= 4;
    }
    while (n >= 1) {
        sym.push_back('I');
        n -= 1;
    }
    
    return sym;
}


int main() {
    string sym_a, sym_b;
    int a, b;
    cin >> sym_a;
    cin >> sym_b;
    a = to_num(sym_a);
    b = to_num(sym_b);
    cout << a+b << endl;
    cout << to_sym(a+b);
    return 0;
}