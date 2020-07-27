#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<ll> buildTree(vector<ll> &nums) {
    vector<ll> tree(nums.size() * 2);
    for (int i = nums.size(); i < tree.size(); i ++) {
        tree[i] = nums[i - nums.size()];
    }
    for (int i = nums.size() - 1; i >= 1; i --) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    return tree;
}

//query range from [left, right]
ll query(vector<ll> &tree, ll left, ll right) {
    left += tree.size() / 2;
    right += tree.size() / 2;
    ll res = 0;
    while (left <= right) {
        if (left % 2 == 1) res += tree[left++];
        if (right % 2 == 0) res += tree[right--];
        left /= 2;
        right /= 2;
    }
    return res;
}

void update(vector<ll> &tree, ll pos, ll value) {
    pos += tree.size() / 2;
    tree[pos] = value;
    for (pos /= 2; pos >= 1; pos /= 2) {
        tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
    }
}

int main() {
    ll n; ll q;
    cin >> n >> q;
    vector<ll> nums;
    while (n-- > 0) {
        ll in; cin >> in;
        nums.push_back(in); 
    }

    auto tree = buildTree(nums);
    vector<ll> res;

    while (q-- > 0) {
        ll type; ll x; ll y;
        cin >> type >> x >> y;
        if (type == 1) {
            x --;
            update(tree, x, y); //update position x to value y
            // cout << "tree: " << endl;
            // for (auto t : tree) cout << t << " ";
            // cout << endl;
        }
        else {
            x --; y --;
            res.push_back(query(tree, x, y)); //query from [x, y]
        }
    }
    
    for (auto r : res) cout << r << endl;
}