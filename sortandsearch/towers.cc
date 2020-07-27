#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ll n; cin >> n;
    
    vector<ll> towers;

    while (n-- > 0) {
        ll tower; cin >> tower;
        auto it = upper_bound(towers.begin(), towers.end(), tower);
        //tower to stack not found, make a new one
        if (it == towers.end()) {
            towers.push_back(tower);
        } else {
            *it = tower;
        }
    }

    cout << towers.size() << "\n";
}