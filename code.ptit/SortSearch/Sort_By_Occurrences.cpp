/*
 * Cho mảng A[] gồm n số nguyên. Nhiệm vụ của bạn là
 * sắp xếp mảng theo số lần xuất hiện các phần tử của mảng.
 * Số xuất hiện nhiều lần nhất đứng trước.
 * Nếu hai phần tử có số lần xuất hiện như nhau,
 * số nhỏ hơn đứng trước.
 * Ví dụ A[] = {5, 5, 4, 6, 4 }, ta nhận được kết quả
 * là A[] = {4, 4, 5, 5, 6}.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        // tao mang b danh dau so lan xuan hien
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i] == a[j]) {
                    ++b[i];
                    ++b[j];
                }
            }
        }
        // sap xep theo mang b
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // a khac nhau thi sort theo b
                if ((b[j] > b[i] && a[i] != a[j]) ||
                    // b bang nhau thi sort theo a
                    (b[j] == b[i] && a[j] < a[i])) {
                    swap(b[j], b[i]);
                    swap(a[j], a[i]);
                }
            }
        }

        for (int k = 0; k < n; ++k) {
            cout << a[k] << " ";
        }
        cout << "\n";
        //        for (int i = 0; i < n; ++i) {
        //            cout << b[i] << " ";
        //        }
    }
    return 0;
}