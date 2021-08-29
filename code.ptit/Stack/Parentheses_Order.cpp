/*
Cho biểu thức số học có chứa các ký tự dấu ngoặc ‘(‘, ‘)’.
Hãy in ra số thứ tự của các cặp ‘(‘, ‘)’ trong biểu thức.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s1, s;
        getline(cin, s1);
        int k = 1;
        stack<int> a;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == '(' || s1[i] == ')') s.push_back(s1[i]);
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                a.push(k);
                cout << k++ << " ";
            } else if (s[i] == ')') {
                cout << a.top() << " ";
                a.pop();
            }
        }
        cout << "\n";
    }
    return 0;
}