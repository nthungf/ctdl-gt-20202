/*
Tại ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000.
Tổng số tiền cần đổi có giá trị bằng N. Hãy xác định xem có ít nhất bao nhiêu
tờ tiền sau khi đổi tiền?
*/
#include <bits/stdc++.h>
using namespace std;

int a[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int i = 0;
        int count = 0;
        while (n > 0) {
            while (n >= a[i]) {
                n -= a[i];
                // cout << " - " << a[i] << "\n";
                ++count;
            }
            ++i;
        }
        cout << count << "\n";
    }
    return 0;
}