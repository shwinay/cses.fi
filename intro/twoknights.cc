#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll getWays(ll n);

int main() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cout << getWays(i) << endl;
    }
}

ll getWays(ll n) {
    pair<ll, ll> directions[8] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-2, -1}, {-1, -2}, {-1, 2}, {-2, 1}};
    ll totalWays = (n * n) * (n * n - 1);
    for (ll i = 0; i < n; i ++) {
        for (ll j = 0; j < n; j ++) {
            for (int k = 0; k < 8; k ++) {
                ll newI = i + directions[k].first;
                ll newJ = j + directions[k].second;
                if (newI < 0 || newJ < 0 || newI >= n || newJ >= n) continue;
                totalWays --;
            }
        }
    }

    return totalWays / 2;
}