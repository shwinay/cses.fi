#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll length; ll lights;
    cin >> length >> lights;

    set<ll> lightSet;
    lightSet.insert(0);
    lightSet.insert(length);
    multiset<ll> lengthSet;
    lengthSet.insert(length);

    while (lengths-- > 0) {
        ll light; cin >> light;
        lightSet.insert(light);
        
    }
}