#include <bits/stdc++.h>

using namespace std;
 
#define ll long long

int main() {
    ll n; ll m; ll k;
    cin >> n >> m >> k;
    vector<ll> desired;
    vector<ll> apartments;
    ll x;
    for (ll i = 0; i < n; i ++) {
        cin >> x;
        desired.push_back(x);
    }
    for (ll i = 0; i < m; i ++) {
        cin >> x;
        apartments.push_back(x);
    }
    sort(desired.begin(), desired.end());
    sort(apartments.begin(), apartments.end());

    ll desiredIndex = 0;
    ll apartmentsIndex = 0;

    int count = 0;
    while (desiredIndex < desired.size() && apartmentsIndex < apartments.size()) {
        ll currWanted = desired[desiredIndex];
        ll currListing = apartments[apartmentsIndex];
        //check if match
        if (abs(currWanted - currListing) <= k) {
            count ++;
            desiredIndex ++;
            apartmentsIndex ++;
        }
        //desired higher, so we need to move to a greater available
        else if (currWanted - currListing > k) {
            apartmentsIndex ++;
        }
        else {
            desiredIndex ++;
        }
    }

    cout << count << endl;
}