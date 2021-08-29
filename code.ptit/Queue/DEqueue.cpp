/*
Yêu cầu bạn xây dựng một hàng đợi hai đầu với các truy vấn sau đây:
    - “PUSHFRONT x”: Thêm phần tử x vào đầu của dequeue
                    (0 ≤ x ≤ 1000).
    - “PRINTFRONT”: In ra phần tử đầu tiên của dequeue.
                    Nếu dequeue rỗng, in ra “NONE”.
    - “POPFRONT”: Xóa phần tử đầu của dequeue.
                Nếu dequeue rỗng, không làm gì cả.
    - “PUSHBACK x”: Thêm phần tử x vào cuối của dequeue
                    (0 ≤ x ≤ 1000).
    - “PRINTBACK”: In ra phần tử cuối của dequeue.
                Nếu dequeue rỗng, in ra “NONE”.
    - “POPBACK”: Xóa phần tử cuối của dequeue.
                Nếu dequeue rỗng, không làm gì cả.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    deque<int> dq;
    while (t--) {
        string q;
        cin >> q;
        if (q == "PUSHFRONT") {
            int x;
            cin >> x;
            dq.push_front(x);
        } else if (q == "PRINTFRONT") {
            if (!dq.empty())
                cout << dq.front() << "\n";
            else
                cout << "NONE\n";
        } else if (q == "POPFRONT") {
            if (!dq.empty())
                dq.pop_front();
        } else if (q == "PUSHBACK") {
            int x;
            cin >> x;
            dq.push_back(x);
        } else if (q == "PRINTBACK") {
            if (!dq.empty())
                cout << dq.back() << "\n";
            else
                cout << "NONE\n";
        } else if (q == "POPBACK") {
            if (!dq.empty())
                dq.pop_back();
        }
    }
    return 0;
}