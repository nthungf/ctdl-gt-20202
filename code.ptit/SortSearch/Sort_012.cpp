/*
Cho mảng A[] gồm n phần tử. Các phần tử của mảng A[]
chỉ bao gồm các số 0, 1, 2. Hãy sắp xếp mảng A[] theo
thứ tự tăng dần. Ví dụ với A[] = {0, 2, 1, 2, 0} ta
kết quả A[] = {0, 0, 1, 2, 2}.
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
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}