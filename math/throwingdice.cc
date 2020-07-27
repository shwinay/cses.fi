#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MOD_CONSTANT 1000000007

ll solve(ll n, vector<ll> &dp) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    
    if (dp[n] != -1) return dp[n];

    ll res = 0;
    for (ll i = 1; i <= 6; i ++) {
        res += solve(n - i, dp) % MOD_CONSTANT;
    }

    dp[n] = res % MOD_CONSTANT;
    return res % MOD_CONSTANT;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, -1);
    cout << solve(n, dp) % MOD_CONSTANT << endl;
}

