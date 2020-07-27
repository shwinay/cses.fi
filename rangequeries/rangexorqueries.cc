#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<ll> buildTree(vector<ll> &nums) {
    vector<ll> t(nums.size() * 2);
    for (int i = 0; i < nums.size(); i ++) {
        t[i + nums.size()] = nums[i];
    }
    for (int i = nums.size() - 1; i >= 1; i --) {
        t[i] = t[2 * i] ^ t[2 * i + 1];
    }
    return t;
}

ll query(vector<ll> &t, int left, int right) {
    left += t.size() / 2;
    right += t.size() / 2;
    ll res = 0;
    while (left <= right) {
        if (left % 2 == 1) res ^= t[left++];
        if (right % 2 == 0) res ^= t[right--]; 
        left /= 2;
        right /= 2;
    }
    return res;
}

int main() {
    ll n; ll q;
    cin >> n >> q;
    vector<ll> nums;
    while (n-- > 0) {
        ll x; cin >> x;
        nums.push_back(x);
    }

    auto t = buildTree(nums);
    vector<ll> res;
    while (q-- > 0) {
        ll left; ll right;
        cin >> left >> right;
        left --; right --;
        res.push_back(query(t, left, right));
    }


    for (auto r : res) cout << r << "\n";
}