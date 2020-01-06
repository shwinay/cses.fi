#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll power(ll a, ll b, ll m);

int main() {
    ll n;
    cin >> n;
    cout << power(2, n, 1000000007) << endl;
}

//calculates a^b % m
ll power(ll a, ll b, ll m) {
    if (b <= 0) return 1 % m;
    if (b == 1) return a % m;
    return ((a % m) * power(a, b - 1, m) % m) % m;
}