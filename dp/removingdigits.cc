#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll getMinSteps(ll n, ll count, vector<bool> &isReady, vector<ll> &solutions) {
    if (n < 10) return count + 1;
    ll minWays = INT_MAX;
    ll num = n;
    while (num > 0) {
        ll digit = num % 10;
        if (digit != 0) {
            if (isReady[n - digit]) {
                minWays = min(minWays, solutions[n - digit]);
            }
            else {
                auto answer = getMinSteps(n - digit, count + 1, isReady, solutions);
                isReady[n - digit] = true;
                solutions[n - digit] = answer;
                minWays = min(minWays, answer);
            }
        }
        num /= 10;
    }
    isReady[n] = true;
    solutions[n] = minWays;
    return minWays;
}

ll getMinStepsLong(ll n, ll count) {
    if (n < 10) return count + 1;
    ll minWays = INT_MAX;
    ll num = n;
    while (num > 0) {
        ll digit = num % 10;
        if (digit != 0) minWays = min(minWays, getMinStepsLong(n - digit, count + 1));
        num /= 10;
    }
    return minWays;
}

int main() {
    ll n;
    cin >> n;
    vector<bool> isReady(n + 1, false);
    vector<ll> solutions(n + 1, 0);
    cout << getMinSteps(n, 0, isReady, solutions) << endl;
    cout << getMinStepsLong(n, 0) << endl;
}