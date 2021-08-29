/*
Cho N sợi dây với độ dài khác nhau được lưu
trong mảng A[]. Nhiệm vụ của bạn là nối N sợi dây
thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất.
Biết chi phí nối sợi dây thứ i và sợi dây thứ j là
tổng độ dài hai sợi dây A[i] và A[j].
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            pq.push(x);
        }
        ll opt = 0;
        // cout << pq.top() << "\n";
        while (pq.size() > 1) {
            ll n1 = pq.top();
            pq.pop();
            ll n2 = pq.top();
            pq.pop();
            opt += (n1 % mod + n2 % mod) % mod;
            opt %= mod;
            pq.push((n1 % mod + n2 % mod) % mod);
        }
        cout << opt << "\n";
    }
    return 0;
}