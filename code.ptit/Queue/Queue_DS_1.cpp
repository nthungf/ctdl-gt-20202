/*
Ban đầu cho một queue rỗng. Bạn cần thực hiện các truy vấn sau:
    1. Trả về kích thước của queue
    2. Kiểm tra xem queue có rỗng không,
        nếu có in ra “YES”, nếu không in ra “NO”.
    3. Cho một số nguyên và đẩy số nguyên này vào cuối queue.
    4. Loại bỏ phần tử ở đầu queue nếu queue không rỗng,
        nếu rỗng không cần thực hiện.
    5. Trả về phần tử ở đầu queue, nếu queue rỗng in ra -1.
    6. Trả về phần tử ở cuối queue, nếu queue rỗng in ra -1.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queue<int> q;
        while (n--) {
            int qq;
            cin >> qq;
            switch (qq) {
            case 1:
                cout << q.size() << "\n";
                break;
            case 2:
                q.empty() ? cout << "YES\n" : cout << "NO\n";
                break;
            case 3:
                int num;
                cin >> num;
                q.push(num);
                break;
            case 4:
                if (!q.empty())
                    q.pop();
                break;
            case 5:
                if (q.empty())
                    cout << "-1\n";
                else
                    cout << q.front() << "\n";
                break;
            case 6:
                if (q.empty())
                    cout << "-1\n";
                else
                    cout << q.back() << "\n";
                break;

            default:
                break;
            }
        }
    }
    return 0;
}