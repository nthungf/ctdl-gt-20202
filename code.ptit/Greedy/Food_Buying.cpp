/*
Giả sử bạn là một người nghèo trong địa phương của bạn.
Địa phương của bạn có duy nhất một cửa hàng bán lương thực.
Cửa hàng của bạn mở cửa tất cả các ngày trong tuần ngoại
trừ chủ nhật. Cho bộ ba số N, S, M thỏa mãn ràng buộc sau:

    N : số đơn vị lương thực nhiều nhất bạn có thể mua
    trong ngày.
    S : số lượng ngày bạn cần được sử dụng lương thực
    để tồn tại.
    M : số đơn vị lương thực cần có mỗi ngày để bạn tồn tại.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, S, M;
        cin >> N >> S >> M;
        if ((6 * N < 7 * M && S >= 7) || N < M)
            cout << "-1";
        else {
            int need = M * S;
            int count = need / N;
            if (need % N != 0)
                count++;
            cout << count;
        }
        cout << "\n";
    }
    return 0;
}