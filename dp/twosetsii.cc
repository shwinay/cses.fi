#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MOD_CONSTANT 1000000007

ll solve(vector<ll> &nums, ll index, ll target, vector<vector<ll>> &dp) {
    if (target == 0) return 1;
    if (target < 0 || index >= nums.size() - 1) return 0;
    if (dp[index][target] != -1) return dp[index][target];

    ll include = solve(nums, index + 1, target - nums[index], dp) % MOD_CONSTANT;
    ll skip = solve(nums, index + 1, target, dp) % MOD_CONSTANT;

    dp[index][target] = (include + skip) % MOD_CONSTANT;
    return dp[index][target];
}

int main() {
    ll n; cin >> n;
    vector<ll> nums(n);
    iota(nums.begin(), nums.end(), (ll) 1); 
    ll sum = accumulate(nums.begin(), nums.end(), (ll) 0);
    if (sum % 2 == 1) {
        cout << 0 << endl;
        return 0;
    } 
    vector<vector<ll>> dp(nums.size() + 1, vector<ll>(sum, -1));
    ll res = solve(nums, 0, sum / 2, dp) % MOD_CONSTANT;
    cout << res << endl;
}
