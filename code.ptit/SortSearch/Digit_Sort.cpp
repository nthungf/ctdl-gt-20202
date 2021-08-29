/*
Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là
đưa ra mảng đã được sắp xếp bao gồm các chữ số của
mỗi phần tử trong A[].
Ví dụ A[] = {110, 111, 112, 113, 114 } ta có
kết quả là {0, 1, 2, 3, 4}.
*/

#include <bits/stdc++.h>
using namespace std;

void split(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = a[i]; j > 0; j /= 10) {
            b.push_back(j % 10);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b;
        split(a, b);
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}