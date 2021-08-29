/*
Trong một buổi học toán, giáo viên viết 2 số nguyên,
A và B, và yêu cầu Tèo thực hiện phép cộng.
Tèo không bao giờ tính toán sai, nhưng thỉnh thoảng
cậu ta chép các con số một cách không chính xác.
Lỗi duy nhất của là ghi nhầm '5' thành '6' hoặc ngược lại.
Cho hai số, A và B, tính tổng nhỏ nhất và lớn nhất mà
Tèo có thể nhận được.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    replace(a.begin(), a.end(), '6', '5');
    replace(b.begin(), b.end(), '6', '5');

    stringstream aa(a);
    stringstream bb(b);

    long long n = 0, m = 0;
    aa >> n;
    bb >> m;
    cout << n + m << ' ';
    //

    replace(a.begin(), a.end(), '5', '6');
    replace(b.begin(), b.end(), '5', '6');

    stringstream aaa(a);
    stringstream bbb(b);
    aaa >> n;
    bbb >> m;
    cout << n + m << '\n';

    return 0;
}