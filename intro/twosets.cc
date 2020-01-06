#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    ll sum = (n * (n + 1)) / 2;
    if (sum % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    ll leftIndex = 1;
    ll rightIndex = n;

    ll setCount = 0;
    unordered_set<ll> *firstSet = new unordered_set<ll>();
    while (setCount < sum / 2) {
        if (setCount >= sum / 2) break;
        firstSet->insert(rightIndex);
        setCount += rightIndex;
        rightIndex --;

        if (setCount >= sum / 2) break;

        firstSet->insert(leftIndex);
        setCount += leftIndex;
        leftIndex ++;
        if (setCount >= sum / 2) break;
    }
    unordered_set<ll> *secondSet = new unordered_set<ll>();
    for (ll i = 1; i <= n; i ++) {
        if (firstSet->count(i) == 0) {
            secondSet->insert(i);
        }
    }

    cout << firstSet->size() << endl;
    for (auto elem : (*firstSet)) {
        cout << elem << " ";
    }
    cout << endl;

    cout << secondSet->size() << endl;
    for (auto elem : (*secondSet)) {
        cout << elem << " ";
    }

    cout << endl;
}