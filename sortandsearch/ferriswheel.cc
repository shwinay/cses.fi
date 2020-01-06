#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n; ll x;
    cin >> n >> x;
    vector<ll> weights;
    ll num;
    for (ll i = 0; i < n; i ++) {
        cin >> num;
        weights.push_back(num);
    }

    sort(weights.begin(), weights.end());
    ll leftIndex = 0;
    ll rightIndex = weights.size() - 1;

    while (leftIndex <= rightIndex) {
        ll weight = 0;
        while (weight < x) {
            
        }
    }
}