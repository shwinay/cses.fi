#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll getMinDifference(vector<ll> &nums, ll index, ll pileOne, ll pileTwo);

int main() {
    ll n; cin >> n;
    vector<ll> nums;
    ll temp;
    for (ll i = 0; i < n; i ++) {
        cin >> temp;
        nums.push_back(temp);
    }

    cout << getMinDifference(nums, 0, 0, 0) << endl;
}

ll getMinDifference(vector<ll> &nums, ll index, ll pileOne, ll pileTwo) {
    if (index >= nums.size()) return abs(pileOne - pileTwo);
    return min(getMinDifference(nums, index + 1, pileOne + nums[index], pileTwo), getMinDifference(nums, index + 1, pileOne, pileTwo + nums[index]));
}