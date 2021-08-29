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

int cmp(pair<int, int> x, pair<int, int> y) { return x.second > y.second; }
int cmp1(pair<int, int> x, pair<int, int> y) { return x.first < y.first; }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = 1;
        }
        sort(a.begin(), a.end(), cmp1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i].first == a[j].first) {
                    a[i].second++;
                    a[j].second++;
                }
            }
        }
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < n; ++i) {
            cout << a[i].first << " ";
        }
        cout << "\n";
    }
    return 0;
}