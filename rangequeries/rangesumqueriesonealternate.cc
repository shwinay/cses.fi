#include <bits/stdc++.h>

using namespace std;
#define ll long long


vector<ll> buildTree(vector<ll> &nums) {
    vector<ll> res(nums.size() * 2);
    for (int i = 0; i < nums.size(); i ++) {
        res[nums.size() + i] = nums[i];
    }

    for (int i = nums.size() - 1; i >= 1; i --) {
        res[i] = min(res[2 * i], res[2 * i + 1]);
    }
    return res;
}

ll query(vector<ll> &tree, int left, int right) {
    left += tree.size() / 2;
    right += tree.size() / 2;
    ll res = INT_MAX;
    while (left <= right) {
        if (left % 2 == 1) res = min(res, tree[left++]);
        if (right % 2 == 0) res = min(res, tree[right--]);
        left /= 2;
        right /= 2;
    }
    return res;
}

int main() {
    ll n; ll q;
    cin >> n >> q;
    vector<ll> nums;
    while (n -- > 0) {
        ll x; cin >> x;
        nums.push_back(x);
    }

    auto tree = buildTree(nums);

    vector<ll> res;
    while (q-- > 0) {
        ll left; ll right;
        cin >> left >> right;
        left --; right --;
        res.push_back(query(tree, left, right));
    }

    for (auto r : res) cout << r << endl;
}