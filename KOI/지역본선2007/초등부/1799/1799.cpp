#include <iostream>
#include <vector>

using namespace std;

int n;
int board[10][10] = {0,};
int tr_a[20] = {0,};
int tr_b[20] = {0,};
vector<pair<int, int>> stack_a, stack_b;


int dfs(vector<pair<int, int>>* stack) {
    if (stack->empty()) {
        return 0;
    }
    pair<int, int> p = stack->at(stack->size()-1);
    stack->pop_back();

    int y = p.first;
    int x = p.second;
    int r = 0;
    if (tr_a[x+y] == 0 && tr_b[y-x+n-1] == 0) {
        tr_a[x+y] = 1;
        tr_b[y-x+n-1] = 1;
        r = max(r, 1+dfs(stack));
        tr_a[x+y] = 0;
        tr_b[y-x+n-1] = 0;
    }

    r = max(r, dfs(stack));
    stack->push_back(p);
    return r;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                pair<int, int> p;
                p.first = i;
                p.second = j;
                if ((i+j) % 2 == 0) stack_a.push_back(p);
                else stack_b.push_back(p);
            }
        }
    }

    cout << dfs(&stack_a) + dfs(&stack_b) << endl;

    return 0;
}