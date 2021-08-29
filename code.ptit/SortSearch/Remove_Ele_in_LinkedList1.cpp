/*
Problem
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    list<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cin >> m;
    a.erase(remove(a.begin(), a.end(), m), a.end());
    list<int>::iterator it;
    for (int it = a.begin(); it != a.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    return 0;
}
