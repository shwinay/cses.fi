#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll n; cin >> n;
    vector<ll> nums;
    while (n-- > 0) {
        ll x; cin >> x;
        nums.push_back(x);
    }

    vector<ll> piles;
    for (auto num : nums) {
        auto it = lower_bound(piles.begin(), piles.end(), num);
        if (it == piles.end()) {
            piles.push_back(num);
        }
        else {
            *it = num;
        }
    }

    cout << piles.size() << endl;
}
