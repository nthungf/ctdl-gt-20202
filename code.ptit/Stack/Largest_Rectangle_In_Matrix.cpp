/*
Cho một bảng kích thước NxM, được chia thành lưới ô vuông
đơn vị N dòng M cột. Trên các ô của bảng ghi số 0 hoặc 1.
Các dòng của bảng được đánh số 1, 2... N theo thứ tự
từ trên xuống dưới và các cột của bảng được đánh số
1, 2..., M theo thứ tự từ trái qua phải

Yêu cầu: Hãy tìm một hình chữ nhật gồm các ô của bảng
thoả mãn các điều kiện sau:

1 - Hình chữ nhật đó chỉ gồm các số 1

2 - Cạnh hình chữ nhật song song với cạnh bảng

3 - Diện tích hình chữ nhật là lớn nhất có thể
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int> > a;

void Init() {
    cin >> N >> M;
    a.clear();
    a.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
}

int LargestRecInHtg(vector<int> h) {
    stack<int> stk;
    int ans = 0;
    h.push_back(0);
    for (int i = 0; i < h.size(); i++) {
        while (!stk.empty() && h[i] <= h[stk.top()]) {
            int top = stk.top();
            stk.pop();
            int height = h[top];
            int width;
            if (stk.empty()) width = i;
            else
                width = i - stk.top() - 1;
            int area = height * width;
            ans = max(ans, area);
        }
        stk.push(i);
    }
    return ans;
}

int LargestRecInMat() {
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 1) a[i][j] = a[i - 1][j] + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int maxRow = LargestRecInHtg(a[i]);
        ans = max(ans, maxRow);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        cout << LargestRecInMat() << "\n";
    }
    return 0;
}