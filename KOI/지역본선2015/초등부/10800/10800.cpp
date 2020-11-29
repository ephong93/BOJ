#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<int>> v;
int N;
int colors[200001] = {0,};
bool compare(vector<int> p0, vector<int> p1) {
    return p0.at(1) < p1.at(1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        vector<int> _v;
        _v.push_back(a);
        _v.push_back(b);
        _v.push_back(i);
        v.push_back(_v);
    }

    sort(v.begin(), v.end(), compare);

    //for (int i = 0; i < N; i++) {
    //    cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
    //}


    int arr[200001] = {0,};

    int a = 0;
    int sum = 0;
    while (true) {
        int s = v[a][1];
        int c = v[a][0];
        arr[v[a][2]] = sum - colors[c];

        int b = a+1;
        while (b < N && v[b-1][1] == v[b][1]) {
            int s = v[b][1];
            int c = v[b][0];
            arr[v[b][2]] = sum - colors[c];
            b++;
        }

        for (int i = a; i < b; i++) {
            int s = v[i][1];
            int c = v[i][0];
            sum += s;
            colors[c] += s;
        }
        a = b;
        if (a >= N) break;
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}