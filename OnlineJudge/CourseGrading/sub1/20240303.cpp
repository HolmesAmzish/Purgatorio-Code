// File: 20240303.cpp
// Date: 2024/03/03

#include <iostream>

using namespace std;

void Union(int a[], int m, int b[], int n){
    for (int i = 0; i < m; i++) {
        cout << a[i] << ' ';
    }
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (b[i] == a[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << b[i] << ' ';
        }
    }
    cout << endl;
}

void Diff(int a[], int m, int b[], int n) {
    bool found;
    for (int i = 0; i < m; i++) {
        found = false;
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int m, n;
    int a[100], b[100];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    Union(a, m, b, n);
    Diff(a, m, b, n);

    return 0;
}

/*
6
1 2 3 4 5 6
9
10 9 8 7 6 5 4 3 2
*/