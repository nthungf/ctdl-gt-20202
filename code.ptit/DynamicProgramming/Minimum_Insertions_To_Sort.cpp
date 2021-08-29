/*
Cho mảng A[] gồm N số nguyên.
Nhiệm vụ của bạn là sắp xếp lại mảng số với số lượng
bước là ít nhất. Tại mỗi bước, bạn chỉ được phép chèn
phần tử bất kỳ của mảng vào vị trí bất kỳ trong mảng.
Ví dụ A[] = {2, 3, 5, 1, 4, 7, 6 }sẽ cho ta số phép chèn
ít nhất là 3 bằng cách lấy số 1 chèn trước số 2,
lấy số 4 chèn trước số 5, lấy số 6 chèn trước số 7
ta nhận được mảng được sắp.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        fill(b.begin(), b.end(), 0);
        b[0] = 1;
        for (int i = 1; i < n; i++) {
            int tmp = a[i];
            int max = 0;
            for (int j = 0; j < i; j++) {
                if (a[j] <= tmp && b[j] > max) {
                    max = b[j];
                }
            }
            b[i] = max + 1;
        }
        // for (int i = 0; i < n; i++) {
        //     cout << b[i] << " ";
        // }
        // cout << "\n";
        int x = *max_element(b.begin(), b.end());
        cout << n - x << "\n";
    }
    return 0;
}