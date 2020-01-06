#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i ++) {
        ll a; ll b;
        cin >> a;
        cin >> b;
        if ((2*b - a) % 3 == 0 && (2*a - b) % 3 == 0 && (2*b-a) >= 0 && (2*a-b >= 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}