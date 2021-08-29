/*
Cho mảng A[] gồm n phần tử.
Hãy đưa ra các phần tử nhỏ hơn tiếp theo
của phần tử lớn hơn đầu tiên phần tử hiện tại.
Nếu phần tử hiện tại không có phần tử lớn hơn
tiếp theo ta xem là -1.
Nếu phần tử không có phần tử nhỏ hơn tiếp theo
ta cũng xem là -1.

A[] = {5, 1, 9, 2, 5, 1, 7}
ans = {2, 2, -1, 1, -1, -1, -1}
*/

#include <bits/stdc++.h>
using namespace std;

struct id {
    int value, index;
};

// id next_greater[max], right_smaller[max];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<id> a(n), next_greater(n + 5), right_smaller(n + 5);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].value;
            a[i].index = i;
        }
        a.push_back({-1, n});

        // next greater
        stack<id> st;
        st.push(a[0]);
        for (int i = 1; i < n; ++i) {
            id next = a[i];
            while (!st.empty() && next.value > st.top().value) {
                next_greater[st.top().index] = next;
                st.pop();
            }
            st.push(next);
        }
        while (!st.empty()) {
            next_greater[st.top().index] = {n + 4, n + 4};
            st.pop();
        }

        // right smaller
        st.push(a[0]);
        for (int i = 1; i < n; ++i) {
            id next = a[i];
            while (!st.empty() && next.value < st.top().value) {
                right_smaller[st.top().index] = next;
                st.pop();
            }
            st.push(next);
        }
        while (!st.empty()) {
            right_smaller[st.top().index] = {-1, -1};
            st.pop();
        }
        right_smaller[n + 4] = {-1, n + 4};

        for (int i = 0; i < n; ++i) {
            cout << right_smaller[next_greater[i].index].value << " ";
        }
        cout << "\n";
    }
    return 0;
}
