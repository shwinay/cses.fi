#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(vector<ll> &coins, int index, int amount, vector<vector<int>> &dp) {
    if (amount == 0) return true;
    if (amount < 0 || index >= coins.size()) return false;
    if (dp[index][amount] != -1) {
        return dp[index][amount] == 0 ? false : true;
    }

    bool res = solve(coins, index + 1, amount - coins[index], dp) || solve(coins, index + 1, amount, dp); 
    dp[index][amount] = res;

    return res;
}

int main() {
    ll n; cin >> n;
    vector<ll> coins;
    while (n -- > 0) {
        ll x; cin >> x;
        coins.push_back(x);
    }    

    sort(coins.begin(), coins.end());
    int sum = accumulate(coins.begin(), coins.end(), 0);
    vector<ll> res;

    //dp[index][amount]: -1 is unknown, 0 is false, 1 is true
    vector<vector<int>> dp(coins.size() + 1, vector<int>(sum + 1, -1));
    for (ll i = 1; i <= sum; i ++) {
        if (solve(coins, 0, i, dp)) res.push_back(i);
    }
    cout << res.size() << endl;
    for (auto r : res) cout << r << " ";
    cout << endl;
}