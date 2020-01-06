#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll getMinCoins(vector<ll> &coins, ll amount, bool isReady[], ll solution[]) {
    if (amount == 0) return 0;

    ll minVal = INT_MAX;
    for (auto coin : coins) {
        if (amount - coin < 0) continue;
        ll answer;
        if (isReady[amount - coin]) answer = solution[amount - coin];
        else {
            answer = getMinCoins(coins, amount - coin, isReady, solution);
            isReady[amount - coin] = true;
            solution[amount - coin] = answer;
        }
        minVal = min(minVal, answer + 1);
    }

    return minVal;
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

    ll answer = getMinCoins(coins, amount, isReady, solution);
    if (answer == INT_MAX) cout << -1 << endl;
    else cout << answer << endl;
}