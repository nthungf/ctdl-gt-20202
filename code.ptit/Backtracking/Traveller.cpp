/*
Cho n thành phố đánh số từ 1 đến n và các tuyến đường
giao thông hai chiều giữa chúng, mạng lưới giao thông
này được cho bởi mảng C[1…n, 1…n] ở đây C[i][j] = C[j][i]
là chi phí đi đoạn đường trực tiếp từ thành phố i đến
thành phố j.

Một người du lịch xuất phát từ thành phố 1,
muốn đi thăm tất cả các thành phố còn lại mỗi
thành phố đúng 1 lần và cuối cùng quay lại
thành phố 1.
Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.
*/

#include <bits/stdc++.h>
using namespace std;
#define max 18

int c[max][max], used[max];
int n;
int X[max];
int cost = 0;
int minn = INT_MAX, cmin = INT_MAX;
int check = 0;

void output() {
    for (int i = 0; i <= n; i++) {
        cout << X[i] << " ";
    }
    cout << "\n";
}

void Try(int i) {
    for (int j = 2; j <= n; j++) {
        if (!used[j]) {
            X[i] = j;
            used[j] = 1;
            cost += c[X[i - 1]][j];
            // cout << "+" << c[i][j] << "\n";
            if (i == n - 1) {
                // output();
                int res = cost + c[X[i]][1];
                if (res < minn) {
                    minn = res;
                }
            } else if (cost + (n - i + 1) * cmin < minn)
                Try(i + 1);
            used[j] = 0;
            cost -= c[X[i - 1]][j];
            // cout << "-" << c[i][j] << "\n";
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        used[i] = 0;
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] < cmin)
                cmin = c[i][j];
        }
    }
    used[1] = 1;
    X[0] = 1;
    X[n] = 1;
    Try(1);
    cout << minn << '\n';

    return 0;
}