/*
Cho xâu ký tự S. Ta gọi giá trị của xâu S là tổng
bình phương số lần xuất hiện mỗi ký tự trong S.
Hãy tìm giá trị nhỏ nhất của xâu S sau khi
thực hiện K lần loại bỏ ký tự.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string s;
        cin >> s;
        int freq[26] = {};
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'A']++;
        }
        // char x = 'A';
        // for (int i = 0; i < 26; i++) {
        //     cout << x++ << " ";
        //     cout << freq[i] << "\n";
        // }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push(freq[i]);
        }
        while (k--) {
            int tmp = pq.top();
            pq.pop();
            tmp--;
            pq.push(tmp);
        }
        long long sum = 0;
        while (!pq.empty()) {
            long long tmp = pq.top();
            pq.pop();
            sum += tmp * tmp;
        }
        cout << sum << "\n";
    }
    return 0;
}