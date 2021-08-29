/*
Cho tập từ ghi trong trừ điển dic[] và một bảng
hai chiều A[M][N] các ký tự.
Hãy tạo nên tất cả các từ có mặt trong từ điển dic[]
bằng cách nối các ký tự kề nhau trong mảng A[][].
Chú ý, phép nối các ký tự kề nhau trong mảng A[][]
được thực hiện theo 8 hướng nhưng không có phần tử
A[i][j] nào được lặp lại.
Ví dụ với từ điển dic[] ={ “GEEKS”, “FOR”, “QIUZ”, “GO”}
và mảng A[][] dưới đây sẽ cho ta kết quả: “GEEKS”, “QUIZ”
*/

#include <bits/stdc++.h>
using namespace std;

int k, m, n;
string dict[120];
string res;
char a[5][5];
int b[5][5];
int check;

void Init() {
    cin >> k >> m >> n;
    res.clear();
    check = 0;
    for (int i = 0; i < k; i++) {
        cin >> dict[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }
}

int Search(string res) {
    for (int i = 0; i < k; i++) {
        if (res == dict[i])
            return 1;
    }
    return 0;
}

void Try(int x, int y, string res) {
    // cout << res << "\n";
    if (Search(res)) {
        cout << res << " ";
        check = 1;
    }
    // 1 trai tren
    if (x - 1 >= 0 && y - 1 >= 0 && !b[x - 1][y - 1]) {
        b[x - 1][y - 1] = 1;
        Try(x - 1, y - 1, res + a[x - 1][y - 1]);
        b[x - 1][y - 1] = 0;
    }
    // 2 tren
    if (x - 1 >= 0 && !b[x - 1][y]) {
        b[x - 1][y] = 1;
        Try(x - 1, y, res + a[x - 1][y]);
        b[x - 1][y] = 0;
    }
    // 3 phai tren
    if (x - 1 >= 0 && y + 1 < n && !b[x - 1][y + 1]) {
        b[x - 1][y + 1] = 1;
        Try(x - 1, y + 1, res + a[x - 1][y + 1]);
        b[x - 1][y + 1] = 0;
    }
    // 4 phai
    if (y + 1 < n && !b[x][y + 1]) {
        b[x][y + 1] = 1;
        Try(x, y + 1, res + a[x][y + 1]);
        b[x][y + 1] = 0;
    }
    // 5 phai duoi
    if (x + 1 < m && y + 1 < n && !b[x + 1][y + 1]) {
        b[x + 1][y + 1] = 1;
        Try(x + 1, y + 1, res + a[x + 1][y + 1]);
        b[x + 1][y + 1] = 0;
    }
    // 6 duoi
    if (x + 1 < m && !b[x + 1][y]) {
        b[x + 1][y] = 1;
        Try(x + 1, y, res + a[x + 1][y]);
        b[x + 1][y] = 0;
    }
    // 7 trai duoi
    if (x + 1 < m && y - 1 >= 0 && !b[x + 1][y - 1]) {
        b[x + 1][y - 1] = 1;
        Try(x + 1, y - 1, res + a[x + 1][y - 1]);
        b[x + 1][y - 1] = 0;
    }
    // 8 trai
    if (y - 1 >= 0 && !b[x][y - 1]) {
        b[x][y - 1] = 1;
        Try(x, y - 1, res + a[x][y - 1]);
        b[x][y - 1] = 0;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // res.clear();
                Try(i, j, res);
            }
        }
        if (check == 0) {
            cout << "-1\n";
        }
    }
}
return 0;
}