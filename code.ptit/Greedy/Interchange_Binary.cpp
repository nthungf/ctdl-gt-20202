/*
Một xâu nhị phân được gọi là xen kẽ nếu giá trị 0 ở ngay bên cạnh
giá trị 1 và không có hai giá trị nào bằng nhau ở cạnh nhau.
Hãy viết chương trình liệt kê các xâu nhị phân xen kẽ có độ dài N.
*/

#include <bits/stdc++.h>
using namespace std;

string s1, s2;

void preCalc() {
    s1.resize(1001);
    fill(s1.begin(), s1.end(), '0');
    for (int i = 1; i < 1001; i += 2) {
        s1[i] = '1';
    }
    s2 = s1;
    s2.pop_back();
    s2.insert(0, "1");
}

int main() {
    preCalc();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cout << s1[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << s2[i] << " ";
    cout << "\n";
    return 0;
}