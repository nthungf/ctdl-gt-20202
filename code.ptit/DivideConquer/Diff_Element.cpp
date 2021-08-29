/*
Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N-1 phần tử.
Các phần tử của mảng A[] chỉ khác mảng B[] một phần tử duy nhất.
Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[].
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n - 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        int x = 0;
        while (a[x] == b[x]) {
            x++;
        }
        cout << x + 1 << "\n";
    }
    return 0;
}