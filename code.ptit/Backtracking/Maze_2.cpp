/*
Cho một mê cung bao gồm các khối được biểu diễn như một
ma trận nhị phân A[N][N]. Một con chuột đi từ ô đầu tiên
góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1])
theo nguyên tắc:
    Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
    Right (R): Chuột được phép sang phải dưới nếu ô bên phải
                nó có giá trị 1.
    Left (L): Chuột được phép sang trái dưới nếu ô bên trái
                nó có giá trị 1.
    Up (U): Chuột được phép lên trên nếu ô trên nó có giá trị 1.

*/

#include <bits/stdc++.h>
using namespace std;
#define max 20

int a[max][max];
int n, dem;
string res;

void Init() {
    dem = 0;
    res.clear();
    cin >> n;
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void Try(int x, int y) {
    if (x == n - 1 && y == n - 1) {
        cout << res << " ";
        ++dem;
        return;
    }
    if (a[x + 1][y] && x < n - 1) {
        a[x + 1][y] = 0;
        res.push_back('D');
        Try(x + 1, y);
        a[x + 1][y] = 1;
        res.pop_back();
    }
    if (a[x][y - 1] && y > 0) {
        a[x][y - 1] = 0;
        res.push_back('L');
        Try(x, y - 1);
        a[x][y - 1] = 1;
        res.pop_back();
    }
    if (a[x][y + 1] && y < n - 1) {
        a[x][y + 1] = 0;
        res.push_back('R');
        Try(x, y + 1);
        a[x][y + 1] = 1;
        res.pop_back();
    }
    if (a[x - 1][y] && x > 0) {
        a[x - 1][y] = 0;
        res.push_back('U');
        Try(x - 1, y);
        a[x - 1][y] = 1;
        res.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        if (a[0][0] == 1) {
            a[0][0] = 0;
            Try(0, 0);
        }
        if (!dem)
            cout << "-1";
        cout << "\n";
    }
    return 0;
}