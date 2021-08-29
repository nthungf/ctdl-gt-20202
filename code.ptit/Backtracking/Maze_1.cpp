/*
 * Cho một mê cung bao gồm các khối được biểu diễn
 * như một ma trận nhị phân A[N][N].
 * Một con chuột đi từ ô đầu tiên góc trái (A[0][0])
 * đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:
 *   Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
 *   Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
 * Hãy đưa ra một hành trình của con chuột trên mê cung.
 * Đưa ra -1 nếu chuột không thể đi đến đích.
 */
// uu tien Down

#include <bits/stdc++.h>
using namespace std;
#define max 12

int a[max][max];
string res;
int dem;

void Try(int x, int y, int n) {
    if (x == n - 1 && y == n - 1 && a[x][y] == 1) {
        cout << res << ' ';
        ++dem;
    }
    if (a[x + 1][y] == 1) {
        res.push_back('D');
        // cout << "--" << res << "\n";
        Try(x + 1, y, n);
        res.pop_back();
    }
    if (a[x][y + 1] == 1) {
        res.push_back('R');
        Try(x, y + 1, n);
        res.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        dem = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        if (a[0][0] == 1)
            Try(0, 0, n);
        if (dem == 0) {
            cout << "-1";
        }
        cout << "\n";
        // cout << res << "\n";
    }
}