/*

*/

#include <bits/stdc++.h>
using namespace std;

int n, x;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        multimap<int, int> m;
        multimap<int, int>::iterator it;
        for (int i = 0; i < n; i++) {
            m.insert(make_pair(abs(x - a[i]), a[i]));
        }
        int i = 0;
        for (it = m.begin(); it != m.end(); it++) {
            a[i++] = it->second;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}