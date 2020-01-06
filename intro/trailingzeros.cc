#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll powersOfFive(ll n);

int main() {
    int n;
    cin >> n;
    ll powerOfFive = 5;
    int count = 0;
    while (powerOfFive <= n) {
        count += n / powerOfFive;
        powerOfFive *= 5;
    }
    cout << count << endl;
}