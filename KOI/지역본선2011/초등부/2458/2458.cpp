#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g1, g2;
int N, K;
bool visited[501] = {false,};

void traverse_a(int s) {
    for (int i = 0; i < g1[s].size(); i++) {
        if (!visited[g1[s][i]]) {
            visited[g1[s][i]] = true;
            traverse_a(g1[s][i]);
        }
    }
}

void traverse_b(int s) {
    for (int i = 0; i < g2[s].size(); i++) {
        if (!visited[g2[s][i]]) {
            visited[g2[s][i]] = true;
            traverse_b(g2[s][i]);
        }
    }
}

bool check(int s) {
    for (int i = 1; i <= N; i++) visited[i] = false;
    visited[s] = true;
    traverse_a(s);
    traverse_b(s);
    for (int i = 1; i <= N; i++) if (!visited[i]) return false;
    return true;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        vector<int> v1, v2;
        g1.push_back(v1);
        g2.push_back(v2);
    }

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }

    int r = 0;
    for (int i = 1; i <= N; i++) {
        if (check(i)) r++;
    }

    cout << r << endl;
    return 0;
}