#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<ll> buildTree(vector<ll> &nums) {
    vector<ll> t(nums.size() * 2, 0);
    for (int i = nums.size(); i < t.size(); i ++) t[i] = nums[i - nums.size()];
    for (int i = nums.size() - 1; i >= 1; i --) t[i] = min(t[2 * i], t[2 * i + 1]);
    return t;
}

ll query(vector<ll> &t, ll left, ll right) {
    left += t.size() / 2; right += t.size() / 2;
    ll res = INT_MAX;
    while (left <= right) {
        if (left % 2 == 1) res = min(res, t[left++]);
        if (right % 2 == 0) res = min(res, t[right--]);
        left /= 2;
        right /= 2;
    }
    return res;
}

void update(vector<ll> &t, ll pos, ll value) {
    pos += t.size() / 2;
    t[pos] = value;
    for (pos /= 2; pos >= 1; pos /= 2) {
        t[pos] = min(t[2 * pos], t[2 * pos + 1]);
    }
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
        ll a; ll b; ll c;
        cin >> a >> b >> c;
        if (a == 1) { //update value at pos b to value c
            b --;
            update(t, b, c);
        } else { //range query [b, c]
            b --; c --;
            res.push_back(query(t, b, c));
        }
    }

    for (auto r : res) cout << r << endl;
}