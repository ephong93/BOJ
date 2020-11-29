#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<vector<int>> g;
vector<int> path;
long long arr[1001];
int dp[1001];
int MAX = 10000;


long long to_bin(string s) {
    long long e = 1;
    long long r = 0;
    for (int i = 0; i < K; i++) {
        if (s[i] == '1') r += e;
        e *= 2;
    }
    return r;
}

bool connected(int a, int b) {
    long long d = arr[a]^arr[b];
    int e = 1;
    for (int i = 0; i < K; i++) {
        if (d == e) return true;
        e *= 2;
    }
    return false;
}

void construct() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (connected(i, j)) {
                g[i].push_back(j);
            }
        }
    }
}


int dfs(int a, int b) {
    if (a == b) return 0;
    if (dp[a] >= 0) return dp[a];
    int r = MAX;
    dp[a] = MAX;
    for (int i = 0; i < g[a].size(); i++) {
        r = min(r, 1+dfs(g[a][i], b));      
    }
    dp[a] = r;
    return r;
}

void find_path(int a, int b) {
    if (a == b) return;
    for (int i = 0; i < g[a].size(); i++) {
        if (dfs(a, b) == 1+dfs(g[a][i], b)) {
            path.push_back(g[a][i]+1);
            find_path(g[a][i], b);
            return;
        }
    }
}


int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        arr[i] = to_bin(s);
        vector<int> v;
        g.push_back(v);
    }

    construct();

    for (int i = 0; i < N; i++) dp[i] = -1;
    int a, b;
    cin >> a >> b;

    if (dfs(a-1, b-1) < MAX) {
        path.push_back(a);
        find_path(a-1, b-1);

        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }        
    
    return 0;
}