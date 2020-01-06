#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    vector<ll> *nums = new vector<ll>();
    for (ll i = 0; i < n; i ++) {
        ll x;
        cin >> x;
        nums->push_back(x);
    }

    sort(nums->begin(), nums->end());
    int count = 1;
    int currElem = nums->at(0);
    for (int i = 0; i < nums->size(); i ++) {
        if (nums->at(i) != currElem) {
            count ++;
            currElem = nums->at(i);
        }
    }

    cout << count << endl;
}