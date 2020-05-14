#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll nums; ll queries;
    cin >> nums >> queries;
    vector<ll> prefixSum;
    
    ll n;
    for (ll i = 0; i < nums; i ++) {
        cin >> n;
        if (i == 0) {
            prefixSum.push_back(n);
            continue;
        }
        prefixSum.push_back(prefixSum[i - 1] + n);
    }

    vector<ll> answers;
    ll low; ll high;
    for (ll i = 0; i < queries; i ++) {
        cin >> low >> high;
        low --; high --;
        if (low == 0) {
            answers.push_back(prefixSum[high]);
        } else {
            answers.push_back(prefixSum[high] - prefixSum[low - 1]);
        }
    }

    for (auto answer : answers) {
        cout << answer << endl;
    }

    return 0;
}