#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;
    vector<ll> nums;
    ll elem;
    for (ll i = 0; i < n; i ++) {
        cin >> elem;
        nums.push_back(elem);
    }

    ll maxSum = nums[0];
    ll runningSum = nums[0];
    for (ll i = 1; i < nums.size(); i ++) {
        runningSum = max(runningSum + nums[i], nums[i]);
        maxSum = max(maxSum, runningSum);
    }

    cout << maxSum << endl;
}