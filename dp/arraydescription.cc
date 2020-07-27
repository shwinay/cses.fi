#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll n; ll m;
    cin >> n >> m;
    vector<ll> nums;
    while (n -- > 0) {
        ll x; cin >> x;
        nums.push_back(x);
    }

    int res = 1;

    for (int i = 0; i < nums.size(); i ++) {
        int curr = 0;
        if (i == 0 && nums[i] == 0) {

        }
        else if (i == nums.size() - 1 && nums[i] == 0) {

        }
        else if (nums[i] == 0) {
             if (abs(nums[i - 1] - nums[i + 1]) == 2) curr = 1;
             else if ()
        }
    }

    return res;
}