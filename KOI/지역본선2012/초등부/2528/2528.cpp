#include <iostream>
#include <vector>

using namespace std;

int N, L;
vector<vector<int>> floors;

int compute_time(vector<int> v0, vector<int> v1) {
    int a0 = v0[0], b0 = v0[1], c0 = v0[2];
    int a1 = v1[0], b1 = v1[1], c1 = v1[2];

    int t;

    if (min(a1, b1) <= a0 && a0 <= max(a1, b1)) t = 0;
    else if(min(a1, b1) <= b0 && b0 <= max(a1, b1)) t = 0;
    else if(min(a0, b0) <= a1 && a1 <= max(a0, b0)) t = 0;
    else if(min(a0, b0) <= b1 && b1 <= max(a0, b0)) t = 0;
    else if (c0 == 0 && c1 == 1) {
        t = (a1-b0+1)/2;
    } else if(c0 == 1 && c1 == 0) {
        t = (a0-b1+1)/2;
    } else if (c0 == 0 && c1 == 0) {
        t = (L - b1) + (a1-b0+1)/2;
    } else if(c0 == 1 && c1 == 1) {
        t = a1 + (a0-b1+1)/2;
    }
    return t;
}

void move(int t) {
    for (int i = 0; i < N; i++) {
        int a = floors[i][0], b = floors[i][1], c = floors[i][2];
        int l = abs(a-b);
        if (c == 0 && L-b >= t) {
            floors[i][0] = a+t;
            floors[i][1] = b+t;
            if (b+t == L) floors[i][2] = 1;
            else floors[i][2] = 0;
        } else if(c == 1 && a >= t) {
            floors[i][0] = a-t;
            floors[i][1] = b-t;
            if (a-t == 0) floors[i][2] = 0;
            else floors[i][2] = 1;
        } else if (c == 0) {
            int _t = t-(L-b);
            c = 1;
            a = L-l;
            b = L;
            int d = L-l;

            if ((_t / d) % 2 == 0) {
                a = L - (_t % d) - l;
                b = L - (_t % d);
                if (a == 0) c = 0;
                else c = 1;
            } else {
                a = _t % d;
                b = _t % d + l;
                if (b == L) c = 1;
                else c = 0;
            }
        } else if (c == 1) {
            int _t = t-a;
            c = 0;
            a = 0;
            b = l;
            int d = L-l;

            if ((_t / d) % 2 == 0) {
                a = _t % d;
                b = l + _t % d;
                if (b == L) c = 1;
                else c = 0;
            } else {
                a = L-_t % d-l;
                b = L-_t % d;
                if (a == 0) c = 0;
                else c = 1;
            }
        }
    }
}

int main() {
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int l, d;
        cin >> l >> d;
        int a, b, c;
        if (d == 0) {
            a = 0;
            b = l;
            c = d;
        } else {
            a = L-l;
            b = L;
            c = d;
        }
        vector<int> f;
        f.push_back(a);
        f.push_back(b);
        f.push_back(c);
        floors.push_back(f);
    }

    int r = 0;

    for (int i = 0; i < N-1; i++) {
        int t = compute_time(floors[i], floors[i+1]);
        move(t);
        r += t;
    }

    cout << r << endl;
    return 0;
}