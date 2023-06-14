#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int N = 10;

int m[N][N] = {};
const char* w[N] = {};
int wl[N] = {};

int chk_h(int i, int j, int l, const char* p) {
    if ((!j || m[i][j - 1]=='+') && j + l <= N) {
        for (int k = j; k < j + l; ++k) { if (m[i][k]&& m[i][k]!=p[k-j]) return 0; }
        if (j + l<N && m[i][j + l]!='+') return 0;
        return 1;
    }
    return 0;
}

int chk_v(int i, int j, int l, const char* p) {
    if ((!i || m[i - 1][j] == '+') && i + l <= N) {
        for (int k = i; k < i + l; ++k) { if (m[k][j] && m[k][j] != p[k - i]) return 0; }
        if (i + l<N && m[i + l][j] != '+') return 0;
        return 1;
    }
    return 0;
}

int solve(int iw, int n) {
    if (iw >= n) return 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (m[i][j]!='+') {
                int l = wl[iw];
                if (chk_h(i, j, l, w[iw])) {
                    for (int k = j; k <j + l; ++k) m[i][k] = w[iw][k - j];
                    if (solve(iw + 1, n)) return 1;
                    for (int k = j; k <j + l; ++k) m[i][k] = 0;
                }
                if (chk_v(i, j, wl[iw], w[iw])) {
                    for (int k = i; k <i + l; ++k) m[k][j] = w[iw][k - i];
                    if (solve(iw + 1, n)) return 1;
                    for (int k = i; k <i + l; ++k) m[k][j] = 0;
                }
            }
        }
    }
    return 0;
}
    
int main() {
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            char c ; cin >> c;
            if(c!='-') m[i][j] = c;
        }
    }
    string s; cin >> s;
    
    int n = 0;
    for (const char* p = s.c_str(); *p; ++n) {
        w[n] = p; 
		while (*p && *p != ';') ++p, ++wl[n];
        if (*p) ++p;
    }

    solve(0, n);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << (char)m[i][j];
        }
        cout << endl;
    }
    
    return 0;
}