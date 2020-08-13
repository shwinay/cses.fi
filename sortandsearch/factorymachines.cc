#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll machines; ll product;
    cin >> machines >> product;

    ll produced = 0;
    vector<ll> machineTimings;
    for (int i = 0; i < machines; i ++) {
        ll x; cin >> x;
        machineTimings.push_back(x);
    }

    int time = 0;
    while (produced < product) {
        time ++;
        for (auto m : machineTimings) {
            if (time % m == 0) produced ++;
        }
    }

    cout << time << endl;
}