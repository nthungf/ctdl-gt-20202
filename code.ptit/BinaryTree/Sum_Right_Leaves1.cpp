/*

*/

#include <bits/stdc++.h>
using namespace std;

class edge {
  public:
    int first, last;
    char dir;
};

vector<edge> a;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        a.clear();
        a.resize(n);
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].last >> a[i].dir;
            m.insert(make_pair(a[i].first, i));
        }
        // for (int i = 0; i < m.size(); i++) {
        //     cout << m[i] << " ";
        // }
        // cout << "\n";

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (m.find(a[i].last) == m.end() && a[i].dir == 'R') {
                sum += a[i].last;
                // cout << a[i].last << " ";
            }
        }
        cout << sum << "\n";
    }
    return 0;
}