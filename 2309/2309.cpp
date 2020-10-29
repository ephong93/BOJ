#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


bool combination(int* a, int l, int c, vector<int>* q) {
    if (c == 0) {
        int s = 0;
        for(int i = 0; i < q->size(); i++) {
            s += q->at(i);
        }
        if (s == 100) 
            return true;
        else return false;
    } else if(l == 0) {
        return false;
    }
    for(int i = 0; i < l; i++) {
        q->push_back(a[i]);
        if (combination(a+i+1, l-i-1, c-1, q)) {
            return true;
        }
        q->pop_back();
    }
    return false;
}

int main() {
    int a[9];
    int s = 0;
    for(int i = 0; i < 9; i++) {
        cin >> a[i];
        s += a[i];
    }
    vector<int>* q = new vector<int>;
    combination(a, 9, 7, q);
    sort(q->begin(), q->end());
    for(int i = 0; i < q->size(); i++) cout << q->at(i) << "\n";
    return 0;
}