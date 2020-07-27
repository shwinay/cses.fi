#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll n; cin >> n;
    vector<ll> sticks;
    while (n-- > 0) {
        ll elem; cin >> elem;
        sticks.push_back(elem);
    }

    sort(sticks.begin(), sticks.end());
    ll median = sticks[sticks.size() / 2];
    ll cost = 0;
    for (auto stick : sticks) {
        cost += abs(stick - median);
    }

    cout << cost << endl;
}