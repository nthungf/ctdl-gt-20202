/*
Cho một bàn cờ vua có kích thước n * n, ta biết ràng quân hậu
có thể di chuyển theo chiều ngang, dọc, chéo.
Vấn đề đặt ra rằng, có n quân hậu, bạn cần đếm số cách
đặt n quân hậu này lên bàn cờ sao cho với 2 quân hậu bất kì,
chúng không “ăn” nhau.
*/

#include <bits/stdc++.h>
using namespace std;
#define max 12

int n, dem;
int vitri[max], cot[max], xuoi[2 * max], nguoc[2 * max];

void Init() {
    cin >> n;
    for (int i = 0; i < max; i++) {
        vitri[i] = 0;
        cot[i] = 0;
    }
    for (int i = 0; i < 2 * max; i++) {
        xuoi[i] = 0;
        nguoc[i] = 0;
    }
}

void output() {
    for (int i = 1; i <= n; i++) {
        cout << vitri[i] << " ";
    }
    cout << "\n";
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (!cot[j] && !xuoi[i - j + n] && !nguoc[i + j - 1]) {
            vitri[i] = j;
            cot[j] = 1;
            xuoi[i - j + n] = 1;
            nguoc[i + j - 1] = 1;
            if (i == n) {
                // output();
                ++dem;
            } else
                Try(i + 1);
            cot[j] = 0;
            xuoi[i - j + n] = 0;
            nguoc[i + j - 1] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        dem = 0;
        Init();
        Try(1);
        cout << dem << '\n';
    }
    return 0;
}