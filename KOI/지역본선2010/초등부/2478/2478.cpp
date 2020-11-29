#include <iostream>

using namespace std;

int N;
int arr[501];

void shift_r(int k) {
    int tmp_arr[501];
    for (int i = 0; i < N; i++) {
        tmp_arr[i] = arr[i];
    }
    for (int i = 0; i < N; i++) {
        arr[(i+k)%N] = tmp_arr[i];
    }
}

void reverse(int a, int b) {
    int tmp_arr[501];
    for (int i = 0; i < N; i++) {
        tmp_arr[i] = arr[i];
    }

    for (int i = a; i <= b; i++) {
        arr[i] = tmp_arr[b-(i-a)];
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int a, b;
    a = -1, b = -1;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i]--;
    }


    for (int i = 0; i <= N+1; i++) {
        if ((arr[i%N]+1)%N == arr[(i+1)%N] && (arr[(i+1)%N]+1)%N != arr[(i+2)%N]) a = (i+2)%N;
        else if((arr[i%N]+1)%N != arr[(i+1)%N] && (arr[(i+1)%N]+1)%N == arr[(i+2)%N]) b = i%N;
    }

    if (a == -1) a = 0, b = N-1;
    
    int d;
    if (b < a) d = b + 1 + N - a;
    else d = b - a + 1;

    int r1, r2_0, r2_1, r3;

    r3 = N-a;
    shift_r(N-a);
    
    a = 0;
    b = d-1;

    r2_0 = a+1;
    r2_1 = b+1;

    reverse(a, b);

    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) {
            shift_r(N-i);
            r1 = N-i;
            break;
        }
    }
    
    cout << r1 << endl;
    cout << r2_0 << " " << r2_1 << endl;
    cout << r3 << endl;
    return 0;
}
