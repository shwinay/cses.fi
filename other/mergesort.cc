#include <bits/stdc++.h>

using namespace std;

#define ll long long

void merge(vector<ll> &nums, ll left, ll right) {
    ll mid = left + (right - left) / 2;
    vector<ll> leftArr; vector<ll> rightArr;
    for (ll i = 0; i < mid; i ++)
}

void divide(vector<ll> &nums, ll left, ll right) {
    if (left >= right) return;
    ll mid = left + (right - left) / 2;
    divide(nums, left, mid);
    divide(nums, mid + 1, right);
    merge(nums, left, right);
}

void mergeSort(vector<ll> &nums) {
    divide(nums, 0, nums.size() - 1);
}

void printList(vector<ll> &nums) {
    for (ll i = 0; i < nums.size() - 1; i ++) {
        cout << nums[i] << " ";
    }
    cout << nums[nums.size() - 1] << endl;
}

int main() {
    ll n; cin >> n;
    vector<ll> nums;
    for (ll i = 0; i < n; i ++) {
        ll x; cin >> x;
        nums.push_back(x);
    }

    mergeSort(nums);
    printList(nums);
}