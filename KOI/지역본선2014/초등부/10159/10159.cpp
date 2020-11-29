#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> g;
int N, M;
bool visited[101];
int B[101] = {0,};
int compute(int a) {
    int r = 1;
    for (int i = 0; i < g[a].size(); i++) {
        if (visited[g[a][i]]) continue;
        visited[g[a][i]] = true;
        B[g[a][i]]++;
        r += compute(g[a][i]);
    }
    return r;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        vector<int> v;
        g.push_back(v);
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) visited[j] = false;
        B[i] += compute(i);
    }

    for (int i = 1; i <= N; i++) {
        cout << N-B[i] << endl;
    }

    return 0;
}