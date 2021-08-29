/*
Yêu cầu bạn xây dựng một queue với các truy vấn sau đây:
    “PUSH x”: Thêm phần tử x vào cuối của queue (0 ≤ x ≤ 1000).
    “PRINTFRONT”: In ra phần tử đầu tiên của queue.
        Nếu queue rỗng, in ra “NONE”.
    “POP”: Xóa phần tử ở đầu của queue.
        Nếu queue rỗng, không làm gì cả.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    queue<int> q;
    while (n--) {
        string qq;
        cin >> qq;
        if (qq == "PUSH") {
            int x;
            cin >> x;
            q.push(x);
        } else if (qq == "PRINTFRONT") {
            if (q.empty())
                cout << "NONE\n";
            else
                cout << q.front() << "\n";
        } else if (qq == "POP") {
            if (!q.empty())
                q.pop();
        }
    }
    return 0;
}