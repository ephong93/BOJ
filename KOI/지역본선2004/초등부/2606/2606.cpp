#include <iostream>
#include <vector>


using namespace std;

vector<vector<int>> g;
bool visited[101];

void dfs(int v) {
    if (visited[v]) return;
    visited[v] = true;

    for(int i = 0; i < g[v].size(); i++) {
        int next_v = g[v][i];
        dfs(next_v);
    }
}


int main() {
    int n_v, n_e;
    cin >> n_v;
    cin >> n_e;
    for (int i = 0; i <= n_v; i++) {
        vector<int> e;
        g.push_back(e);
    }

    for (int i = 0; i < n_e; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        //cout << i << n_e << a << b;
    }

    dfs(1);

    int n_infected = 0;
    for (int i = 2; i <= n_v; i++) {
        if (visited[i]) n_infected++;
    }

    cout << n_infected;
    return 0;
}