#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll sum = 0;
    ll n; cin >> n;
    for (ll i = 1; i <= n; i ++) {
        sum += __builtin_popcount(i);
    }
    cout << sum << endl;
}