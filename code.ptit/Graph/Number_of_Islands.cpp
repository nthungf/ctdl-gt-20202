/*
Cho một bản đồ kích thước N x M được mô tả bằng ma trận A[][].
A[i][j] = 1 có nghĩa vị trí (i, j) là nổi trên biển.
2 vị trí (i, j) và (x, y) được coi là liền nhau nếu như nó
có chung đỉnh hoặc chung cạnh.
Một hòn đảo là một tập hợp các điểm (i, j) mà A[i][j] = 1
và có thể di chuyển giữa hai điểm bất kì trong đó.

Nhiệm vụ của bạn là hãy đếm số lượng đảo xuất hiện trên bản đồ.
*/

#include <bits/stdc++.h>
using namespace std;
#define max 510

int N, M, a[max][max], vs[max][max];

int xM[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int yM[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int isValid(int x, int y) { return (x >= 0 && x < N && y >= 0 && y < M && a[x][y]); }

void DFS(int x, int y) {
    vs[x][y] = 1;
    for (int i = 0; i < 8; ++i) {
        int xN = x + xM[i];
        int yN = y + yM[i];
        if (!vs[xN][yN] && isValid(xN, yN)) {
            DFS(xN, yN);
        }
    }
}

int tplt() {
    int dem = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (a[i][j] && !vs[i][j]) {
                DFS(i, j);
                ++dem;
            }
        }
    }
    return dem;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M;
        memset(a, 0, sizeof(a));
        memset(vs, 0, sizeof(vs));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> a[i][j];
            }
        }
        cout << tplt() << "\n";
    }
    return 0;
}
