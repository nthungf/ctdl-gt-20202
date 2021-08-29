/*
Khi chat chit vui vẻ, anh em chiến hữu thường hay gõ HAHA
để thể hiện sự sảng khoái. Đôi khi cũng có thể gõ HAHAAAAA
chẳng hạn cho thêm phần nhấn mạnh.
Giả sử một xâu ký tự được coi là HAHA nếu thỏa mãn các điều kiện:
    Ký tự đầu tiên phải là chữ H, ký tự cuối cùng phải là chữ A
    Không có hai chữ H nào liền nhau
Cho trước độ dài N, hãy liệt kê tất cả các xâu ký tự HAHA
theo thứ tự từ điển.
*/

#include <bits/stdc++.h>
using namespace std;

string s;

bool vs[20];

vector<string> res;

void Try(int i) {
    if (i >= s.size()) {
        return;
    }
    for (int j = i; j < s.size(); j++) {
        if (!vs[j]) {
            s[j] = 'H';
            string tmp = "HA" + s + "A";
            res.push_back(tmp);
            vs[j] = true;
            if (j > 0) vs[j - 1] = true;
            vs[j + 1] = true;
            Try(j + 1);
            s[j] = 'A';
            vs[j] = false;
            if (j > 0) vs[j - 1] = false;
            vs[j + 1] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << "HA\n";
            continue;
        }
        memset(vs, 0, sizeof(vs));
        s.clear();
        s.resize(n - 3);
        fill(s.begin(), s.end(), 'A');
        res.clear();
        res.push_back("HA" + s + "A");

        Try(0);

        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        for (int i = 0; i < res.size(); i++) cout << res[i] << "\n";
    }
    return 0;
}