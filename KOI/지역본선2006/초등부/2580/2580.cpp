#include <iostream>
#include <vector>

using namespace std;

int block[3][3] = {0,};
int rows[9] = {0,};
int cols[9] = {0,};
int board[9][9];

vector<pair<int, int>> stack;


void print_board() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


bool dfs() {
    pair<int, int> top = stack.at(stack.size()-1);
    stack.pop_back();
    for(int i = 1; i <= 9; i++) {
        int block_y = top.first / 3;
        int block_x = top.second / 3;
        int e = 1 << (i-1);
        //cout << block_y << " " << block_x << " " << e << " " << (block[block_y][block_x] & e) << " " << (rows[top.first] & e) << " " << (cols[top.second] & e) << endl;
        if ((block[block_y][block_x] & e) > 0) continue;
        if ((rows[top.first] & e) > 0) continue;
        if ((cols[top.second] & e) > 0) continue;
        board[top.first][top.second] = i;
        block[block_y][block_x] += e;
        rows[top.first] += e;
        cols[top.second] += e;
        if (stack.empty()) return true;
        if (dfs()) return true;
        block[block_y][block_x] -= e;
        rows[top.first] -= e;
        cols[top.second] -= e;
    }
    stack.push_back(top);
    return false;
}




int main() {    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int block_y = i / 3;
            int block_x = j / 3;
            int n;
            cin >> n;
            board[i][j] = n;
            if (n == 0) {
                pair<int, int> p;
                p.first = i;
                p.second = j;
                stack.push_back(p);
                continue;
            }
            int e = 1 << (n-1);
            block[block_y][block_x] += e;
            rows[i] += e;
            cols[j] += e;
        }
    }

    dfs();

    print_board();
    
    return 0;
}