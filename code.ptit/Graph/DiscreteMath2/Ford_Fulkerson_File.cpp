/*

*/

#include <bits/stdc++.h>
using namespace std;

int c[100][100], f[100][100], G_f[100][100];
int vs[100], e[100], d[100];
int n, s, t;

int Val() {
    int val = 0;
    for (int i = 1; i <= n; i++) val += f[1][i];
    return val;
}

void readFile() {
    fstream filein("DT.inp", ios::in);
    filein >> n;
    s = 1;
    t = n;
    // cout << n << "\n";
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            filein >> c[u][v];
            G_f[u][v] = c[u][v];
        }
    }
    filein.close();
}

void writeFile() {
    fstream fileout("DT.out", ios::out);
    fileout << Val() << "\n";
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            fileout << f[u][v] << " ";
        }
        fileout << "\n";
    }
    fileout.close();
}

bool findPath() {
    memset(vs, 0, sizeof(vs));
    memset(e, 0, sizeof(e));
    for (int i = 1; i <= n; ++i) d[i] = 100000;
    queue<int> q;
    q.push(s);
    vs[s] = 1;
    e[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        // cout << u << " ";
        q.pop();
        if (u == t) return true;
        for (int v = 1; v <= n; v++)
            if (!vs[v] && c[u][v] > 0) {
                if (f[u][v] < c[u][v]) {
                    e[v] = u;
                    d[v] = min(d[u], c[u][v] - f[u][v]);
                    q.push(v);
                    vs[v] = 1;
                }
                if (f[v][u] > 0) {
                    e[v] = -u;
                    d[v] = min(d[u], f[v][u]);
                    q.push(v);
                    vs[v] = 1;
                }
            }
    }
    return false;
}

void calc_Gf() {
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (f[u][v] == 0) G_f[u][v] = c[u][v];
            else if (f[u][v] == c[u][v]) {
                G_f[v][u] = f[u][v];
            } else if (0 < f[u][v] && f[u][v] < c[u][v]) {
                G_f[u][v] = c[u][v] - f[u][v];
                G_f[v][u] = f[u][v];
            }
        }
    }
}

void tangLuong_f(int delta) {
    for (int v = t; v != s; v = e[v]) {
        int u = e[v];
        if (u > 0) {
            f[u][v] += delta;
        } else if (u < 0) {
            f[v][-u] -= delta;
        }
    }
}

void maxFlow() {
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++) f[u][v] = 0;
    while (findPath()) {
        calc_Gf();
        int delta = d[t];
        tangLuong_f(delta);
    }
}

int main() {
    readFile();
    maxFlow();
    writeFile();
    return 0;
}