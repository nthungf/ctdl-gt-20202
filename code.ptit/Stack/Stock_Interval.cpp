/*
Bạn là một nhà đầu tư chứng khoán nổi tiếng.
Nhiệm vụ hàng ngày của bạn là tính nhịp tăng giảm của
phiên chứng khoán trong N ngày để có thể bắt kịp thị trường.
Nhịp chứng khoán của ngày thứ i được định nghĩa là số ngày
liên tiếp từ ngày thứ i trở về mà giá chứng khoán
bé hơn hoặc bằng với giá chứng khoán của ngày i.
*/

// Left larger

#include <bits/stdc++.h>
using namespace std;

struct id {
    int val, idx;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<id> a(n + 5), left_larger(n + 5);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].val;
            a[i].idx = i;
        }
        stack<id> st;
        st.push(a[1]);
        for (int i = 2; i <= n; i++) {
            id curr = a[i];
            stack<id> tmp = st;
            while (!tmp.empty() && curr.val >= tmp.top().val) {
                tmp.pop();
            }
            if (!tmp.empty()) left_larger[i] = tmp.top();
            else
                left_larger[i] = {0, 0};

            st.push(curr);
        }
        for (int i = 1; i <= n; i++) {
            // cout << " --- " << a[i].val << " " << left_larger[i].idx << "." << left_larger[i].val
            //  << "\n";
            if (left_larger[i].idx > 0) cout << i - left_larger[i].idx << " ";
            else
                cout << 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
