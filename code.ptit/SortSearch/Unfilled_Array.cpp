/*
Cho mảng A[] gồm n số nguyên dương. Gọi L, R là max và min
các phần tử của A[]. Nhiệm vụ của bạn là tìm số phần tử
cần thiết cần thêm vào mảng để mảng có đầy đủ các số
trong khoảng [L, R]. Ví dụ A[] = {5, 7, 9, 3, 6, 2 }
ta nhận được kết quả là 2 tương ứng với các số còn thiếu là 4, 8.
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int current_size = a.size();
        int full_size = a[a.size() - 1] - a[0] + 1;
        cout << full_size - current_size << "\n";
    }
    return 0;
}