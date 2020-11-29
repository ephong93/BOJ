#include <iostream>

using namespace std;

bool visited[100] = {false, };
int N, P;

int main() {
    cin >> N >> P;
    int a = N;
    while (true) {
        a = (a*N)%P;
        if (visited[a]) break;
        visited[a] = true;
    }
    int check_point = a;
    int r = 0;
    while (true) {
        a = (a*N)%P;
        r++;
        if (a == check_point) break;
    }

    cout << r << endl;
    return 0;
}