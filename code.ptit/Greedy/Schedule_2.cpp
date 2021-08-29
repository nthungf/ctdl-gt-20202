/*
Cho N công việc. Mỗi công việc được biểu diễn như một bộ
3 số nguyên dương <JobId, Deadline, Profit>,
trong đó JobId là mã của việc, Deadline là thời gian
kết thúc của việc, Profit là lợi nhuận đem lại nếu
hoàn thành việc đó đúng thời gian.
Thời gian để hoàn toàn mỗi công việc là 1 đơn vị thời gian.
Hãy cho biết lợi nhuận lớn nhất có thể thực hiện
các việc với giả thiết mỗi việc được thực hiện đơn lẻ.
*/

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int j, d, p;
};

int cmp(Job x, Job y) {
    if (x.p != y.p)
        return x.p > y.p;
    return x.d > y.d;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Job> a(n + 5);
        for (int i = 0; i < n; i++) {
            cin >> a[i].j >> a[i].d >> a[i].p;
        }
        sort(a.begin(), a.end(), cmp);
        // for (int i = 0; i < n; i++) {
        //     cout << a[i].j << " " << a[i].d << " " << a[i].p << '\n';
        // }
        int profit = 0, count = 0;
        vector<int> fill(1010);
        for (int i = 0; i < n; i++) {
            // show(fill, maxx);
            for (int j = a[i].d; j >= 1; j--) {
                if (!fill[j]) {
                    fill[j] = 1;
                    profit += a[i].p;
                    count++;
                    break;
                }
            }
        }
        cout << count << " " << profit << "\n";
    }
    return 0;
}