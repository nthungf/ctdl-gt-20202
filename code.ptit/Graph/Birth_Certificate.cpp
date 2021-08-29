/*
Một buổi họp mặt đại gia đình nhân dịp cụ già Ted
tròn 100 tuổi, người ta muốn sắp xếp con cháu của cụ
theo thứ tự từ tuổi cao xuống thấp.
Giả sử ta có thông tin về giấy khai sinh của từng người đó.
Mỗi giấy khai sinh chỉ viết ba thông tin đơn giản gồm:
Tên người cha, Tên người con, Tuổi của người cha lúc sinh con.

Hãy giúp đại gia đình trên tính ra tuổi của từng người con cháu
cụ Ted và viết ra danh sách theo thứ tự từ tuổi cao xuống thấp.
*/

#include <bits/stdc++.h>
using namespace std;
#define max 110

int x;

struct person {
    string dad_name;
    string name;
    int age;
};

vector<person> res;

bool cmp(pair<int, person> &a, pair<int, person> &b) {
    if (a.second.age != b.second.age) return a.second.age > b.second.age;
    return a.second.name < b.second.name;
}

void BFS(person ted, unordered_map<int, person> &m) {
    queue<person> q;
    q.push(ted);
    while (!q.empty()) {
        person dad = q.front();
        q.pop();
        // cout << dad.name << " ";
        for (int i = 1; i <= x; i++) {
            if (dad.name == m[i].dad_name) {
                m[i].age = dad.age - m[i].age;
                q.push(m[i]);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cin >> x;
        res.clear();
        unordered_map<int, person> m;
        person tmp;
        // m.insert(make_pair(0, tmp));
        for (int i = 1; i <= x; i++) {
            // gan i theo s2, tim i cua s1
            string s1, s2;
            int n;
            cin >> s1 >> s2 >> n;
            tmp = {s1, s2, n};
            m.insert(make_pair(i, tmp));
        }
        tmp = {"", "Ted", 100};
        BFS(tmp, m);
        vector<pair<int, person> > a;
        for (auto it : m) {
            a.push_back(it);
        }
        sort(a.begin(), a.end(), cmp);
        cout << "DATASET " << k << "\n";
        for (int i = 0; i < a.size(); i++) {
            cout << a[i].second.name << " " << a[i].second.age << "\n";
        }
    }
    return 0;
}