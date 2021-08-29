/*
Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j]
nhất định (0 ≤ A[i][j] ≤ 100), tương ứng với điểm
số đạt được nếu như bạn đặt một quân cờ vào đó.

Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ,
sao cho không có 2 quân nào ăn nhau,
và số điểm đạt được là lớn nhất.
*/

#include <bits/stdc++.h>
using namespace std;

#define max 10

int a[max][max];
int point, best;
int vitri[max], cot[max], xuoi[2 * max], nguoc[2 * max];

void Init() {
    best = INT_MIN;
    point = 0;
    for (int i = 1; i <= 8; i++) {
        cot[i] = 0;
        for (int j = 1; j <= 8; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 2 * max; i++) {
        xuoi[i] = 0;
        nguoc[i] = 0;
    }
}

void Try(int i) {
    for (int j = 1; j <= 8; j++) {
        if (!cot[j] && !xuoi[i - j + 8] && !nguoc[i + j - 1]) {
            vitri[i] = j;
            point += a[i][j];
            cot[j] = 1;
            xuoi[i - j + 8] = 1;
            nguoc[i + j - 1] = 1;
            if (i == 8) {
                // cout << point << "\n";
                if (point > best) {
                    best = point;
                }
            } else {
                Try(i + 1);
            }
            point -= a[i][j];
            cot[j] = 0;
            xuoi[i - j + 8] = 0;
            nguoc[i + j - 1] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        Try(1);
        cout << best << "\n";
    }
    return 0;
}