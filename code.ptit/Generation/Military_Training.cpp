/*
Tại Chương Mỹ Resort, vào nửa đêm, cả trung đội nhận lệnh
tập trung ở sân. Mỗi chiến sỹ được đánh số từ 1 đến N (1<N<40).
Giám thị yêu cầu chọn ra một dãy K chiến sỹ để tập đội ngũ
và cứ lần lượt duyệt hết tất cả các khả năng chọn K người
như vậy từ nhỏ đến lớn (theo số thứ tự).
Bài toán đặt ra là cho một nhóm K chiến sỹ hiện đang phải
tập đội ngũ, hãy tính xem trong lượt chọn K người tiếp theo
thì mấy người trong nhóm cũ sẽ được tạm nghỉ.
Nếu đã là nhóm cuối cùng thì tất cả đều sẽ được nghỉ.

Dữ liệu vào: Dòng đầu ghi số bộ test, không quá 20.
Mỗi bộ test viết trên hai dòng
*/

#include <bits/stdc++.h>
using namespace std;

int ok = 1;

void nextCombination(vector<int> &a, int n, int k) {
    int i = k;
    while (i > 0 && a[i] == n - k + i)
        i--;
    if (i > 0) {
        a[i]++;
        for (int j = i + 1; j <= k; j++) {
            a[j] = a[i] + j - i;
        }

    } else
        ok = 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ok = 1;
        int n, k;
        cin >> n >> k;
        vector<int> a(k + 1);
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
        }
        vector<int> b = a;
        nextCombination(b, n, k);
        if (ok) {
            int diff = k;
            for (int i = 1; i < a.size(); i++) {
                for (int j = 1; j < b.size(); j++) {
                    if (a[i] == b[j]) {
                        diff--;
                        a.erase(a.begin() + i);
                        b.erase(b.begin() + j);
                        i = 1;
                        j = 1;
                    }
                }
            }

            cout << diff << "\n";

        } else
            cout << k << "\n";
    }
    return 0;
}