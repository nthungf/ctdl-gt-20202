/*

*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int data, level;

    node() {
        data = 0;
        level = 0;
    }
    node(int u, int v) {
        data = u;
        level = v;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, height = 0;
        node v1, v2;
        unordered_map<int, int> s;
        cin >> n;
        s.insert(make_pair(1, 0));
        for (int i = 0; i < n - 1; i++) {
            cin >> v1.data >> v2.data;
            //  tim v1.level, v2.level = v1.level + 1;
            unordered_map<int, int>::iterator it;
            it = s.find(v1.data);
            v2.level = it->second + 1;
            if (v2.level > height) height = v2.level;
            // cout << v2.level << "\n";
            s.insert(make_pair(v2.data, v2.level));
        }
        cout << height << "\n";
    }
    return 0;
}