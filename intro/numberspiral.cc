#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll getNum(ll y, ll x);

int main() {
    ll numTests;
    cin >> numTests;
    for (ll i = 0; i < numTests; i ++) {
        ll y; ll x;
        cin >> y >> x;
        cout << getNum(y, x) << endl;
    }
}

ll getNum(ll y, ll x) {
    ll ring = max(y, x);
    bool maxValueTop = ring % 2 == 1;
    ll maxVal = ring * ring;
    ll minVal = (ring - 1) * (ring - 1) + 1;
    ll midVal = minVal + (maxVal - minVal) / 2;
    if (y == x) return midVal;
    if (maxValueTop) {
        if (y < x) return maxVal - (y - 1);
        else return minVal + (x - 1);
    }
    else {
        if (y < x) return minVal + (y - 1);
        else return maxVal - (x - 1);
    }

}