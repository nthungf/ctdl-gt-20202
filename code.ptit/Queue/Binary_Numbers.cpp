/*
Cho số tự nhiên n. Hãy in ra tất cả các số nhị phân từ 1 đến n.
*/

// 1) Create an empty queue of strings
// 2) Enqueue the first binary number "1" to queue.
// 3) Now run a loop for generating and printing n binary numbers.
//      a) Dequeue and Print the front of queue.
//      b) Append "0" at the end of front item and enqueue it.
//      c) Append "1" at the end of front item and enqueue it.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queue<string> s;
        s.push("1");
        for (int i = 0; i < n; i++) {
            string s1 = s.front();
            s.pop();
            cout << s1 << " ";

            string s2 = s1;
            s1 += "0";
            s.push(s1);
            s2 += "1";
            s.push(s2);
        }
        cout << "\n";
    }
    return 0;
}