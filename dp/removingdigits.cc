#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> getDigits(ll n);

ll getMinSteps(ll n, vector<ll> &solutions) {
    if (n == 0) return 0;
    if (n < 10) return 1;
    auto digits = getDigits(n);

    ll minSteps = INT_MAX;
    for (auto digit : digits) {
        if (solutions[n - digit] != -1) minSteps = min(minSteps, 1 + solutions[n - digit]);
        else {
            auto answer = getMinSteps(n - digit, solutions);
            solutions[n - digit] = answer;
            minSteps = min(minSteps, 1 + answer);
        }
    }

    solutions[n] = minSteps;
    return minSteps;
}

vector<ll> getDigits(ll n) {
    vector<ll> digits;
    while (n > 0) {
        int digit = n % 10;
        if (digit != 0) digits.push_back(digit);
        n /= 10;
    }
    return digits;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> solutions(n + 1, -1);
    cout << getMinSteps(n, solutions) << endl;
}