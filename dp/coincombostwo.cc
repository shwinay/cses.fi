#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MOD_CONST 1000000007

ll getWays(vector<ll> &coins, ll amount, int coinIndex, vector<vector<ll>> &dp) {
    if (amount == 0) return 1;
    if (coinIndex < 0) return 0;

    if (dp[coinIndex][amount] != -1) return dp[coinIndex][amount];

    ll res = 0;
    ll currCoin = coins[coinIndex];
    if (amount - currCoin >= 0) {
        res += getWays(coins, amount - currCoin, coinIndex, dp) % MOD_CONST;
    }

    res += getWays(coins, amount, coinIndex - 1, dp) % MOD_CONST;

    dp[coinIndex][amount] = res % MOD_CONST;
    return res % MOD_CONST;
}

int main() {
    ll numCoins; ll amount;
    cin >> numCoins >> amount;
    vector<ll> coins;
    while (numCoins -- > 0) {
        ll coin; cin >> coin;
        coins.push_back(coin);
    }

    sort(coins.begin(), coins.end());

    //dp[coinIndex][amount]
    vector<vector<ll>> dp(coins.size(), vector<ll>(amount + 1, -1));
    cout << getWays(coins, amount, coins.size() - 1, dp) << "\n";

}