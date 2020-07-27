#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll solve(ll a, ll b, vector<vector<ll>> &dp) {
    if (a == b) return 0;

    if (dp[a][b] != -1) return dp[a][b];

    ll res = INT_MAX;
    for (int i = 1; i < a; i ++) {
        ll res1 = dp[a - i][b] != -1 ? dp[a - i][b] : solve(a - i, b, dp);
        ll res2 = dp[i][b] != -1 ? dp[i][b] : solve(i, b, dp);
        res = min(res, 1 + res1 + res2);
    }

    for (int i = 1; i < b; i ++) {
        ll res1 = dp[a][b - i] != -1 ? dp[a][b - i] : solve(a, b - i, dp);
        ll res2 = dp[a][i] != -1 ? dp[a][i] : solve(a, i, dp);
        res = min(res, 1 + res1 + res2);
    }

    dp[a][b] = res;
    return res;
}

int main() {
    ll a; ll b;
    cin >> a >> b;
    vector<vector<ll>> dp(a + 1, vector<ll>(b + 1, -1));
    cout << solve(a, b, dp) << endl;
}