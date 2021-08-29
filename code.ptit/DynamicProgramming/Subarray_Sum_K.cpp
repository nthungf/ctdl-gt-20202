/*
Cho dãy số A[] gồm có N phần tử không âm và số K.
Nhiệm vụ của bạn là hãy xác định xem có tìm được 1 dãy con
liên tiếp mà tổng các phần tử bằng K hay không?
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool subarraySumK(vector<ll> a, ll k) {
    unordered_map<ll, ll> m;
    ll ans = 0, curr = 0;
    for (ll i = 0; i < a.size(); i++) {
        curr += a[i];
        ll need = curr - k;
        ans += m[need];
        m[curr]++;
    }
    return (ans > 0);
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (subarraySumK(a, k)) cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}