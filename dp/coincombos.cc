#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define modConstant 1000000007

ll getWays(vector<ll> &coins, ll amount, bool isReady[], ll solution[]) {
    if (amount == 0) return 1;

    ll ways = 0;
    for (ll i = 0; i < coins.size(); i ++) {
        if (amount - coins[i] < 0) continue;
        if (isReady[amount - coins[i]]) {
            ways += solution[amount - coins[i]] % modConstant;
        }
        else {
            auto answer = getWays(coins, amount - coins[i], isReady, solution);
            isReady[amount - coins[i]] = true;
            solution[amount - coins[i]] = answer;
            ways += answer % modConstant;
        }
    }

    isReady[amount] = true;
    solution[amount] = ways;

    return ways % modConstant;
}

int main() {
    ll numCoins; ll amount;
    cin >> numCoins >> amount;
    vector<ll> coins;
    ll x;
    for (ll i = 0; i < numCoins; i ++) {
        cin >> x;
        coins.push_back(x);
    }
    bool isReady[amount + 1];
    for (ll i = 0; i < amount + 1; i ++) isReady[i] = false;
    isReady[0] = true;
    ll solution[amount + 1];
    for (ll i = 0; i < amount + 1; i ++) solution[i] = 0;
    solution[0] = 1;

    cout << getWays(coins, amount, isReady, solution) << endl;
}