#include <bits/stdc++.h>

using namespace std;
#define ll long long


ll solve(vector<ll> &nums, ll left, ll right, vector<vector<ll>> &dp) {
    if (left == right) return nums[left];
    if (dp[left][right] != -1) return dp[left][right]; 
    ll res = max(nums[left] - solve(nums, left + 1, right, dp), nums[right] - solve(nums, left, right - 1, dp));
    dp[left][right] = res;
    return res;
}

int main() {
    ll n; cin >> n;
    vector<ll> nums;
    while (n-- > 0) {
        ll x; cin >> x;
        nums.push_back(x);
    }

    ll sum = accumulate(nums.begin(), nums.end(), (ll) 0);
    vector<vector<ll>> dp(nums.size() + 1, vector<ll>(nums.size() + 1, -1));
    cout << (solve(nums, 0, nums.size() - 1, dp) + sum) / 2 << endl;
}