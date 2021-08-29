
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n); // array of heights
        for (ll i = 0; i < n; ++i) cin >> a[i];
        a.push_back(0);

        // for (int i = 0; i < n; i++) cout << i << " ";
        // cout << "\n";

        ll ans = 0;
        stack<ll> st; // stack of indices
        st.push(0);
        for (ll i = 1; i < a.size(); ++i) {
            ll curr = a[i];
            if (curr >= a[st.top()]) st.push(i);
            else {
                while (!st.empty() && curr < a[st.top()]) {
                    ll top = st.top();
                    st.pop();
                    ll height = a[top];
                    ll width;
                    if (st.empty()) width = i;
                    else
                        width = i - st.top() - 1;

                    ll area = height * width;
                    // cout << top << " " << height << " " << width << " " << area << "\n";
                    ans = max(ans, area);
                }
                st.push(i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}