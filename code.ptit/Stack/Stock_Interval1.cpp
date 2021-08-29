/*
Bạn là một nhà đầu tư chứng khoán nổi tiếng.
Nhiệm vụ hàng ngày của bạn là tính nhịp tăng giảm của
phiên chứng khoán trong N ngày để có thể bắt kịp thị trường.
Nhịp chứng khoán của ngày thứ i được định nghĩa là số ngày
liên tiếp từ ngày thứ i trở về mà giá chứng khoán
bé hơn hoặc bằng với giá chứng khoán của ngày i.
*/

#include <bits/stdc++.h>
using namespace std;

struct day {
    int val;
    int last_days;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<day> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].val;
            a[i].last_days = 1;
            int j = i - 1;
            while (j > 0 && a[j].val <= a[i].val) {
                a[i].last_days++;
                j--;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i].last_days << " ";
        }
        cout << "\n";
    }
    return 0;
}
