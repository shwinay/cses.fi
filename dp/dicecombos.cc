#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define modConstant 1000000007

ll getCombos(ll n, ll solutions[], bool ready[]) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    ll ways = 0;
    for (ll i = 1; i <= 6; i ++) {
        if (n - i < 0) continue;
        if (ready[n - i]) ways += solutions[n - i] % modConstant;
        else {
            ll answer = getCombos(n - i, solutions, ready);
            ready[n - i] = true;
            solutions[n - i] = answer;
            ways += answer % modConstant;
        }
    }
    return ways % modConstant;
}

int main() {
    ll n;
    cin >> n;

    ll solutions[n + 1];
    for (ll i = 0; i < n + 1; i ++) solutions[i] = 0;
    bool ready[n + 1];
    for (ll i = 0; i < n + 1; i ++) ready[i] = false;

    ready[0] = true;
    solutions[0] = 1;

    cout << getCombos(n, solutions, ready) << endl;
}