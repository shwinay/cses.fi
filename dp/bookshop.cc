#include <bits/stdc++.h>

using namespace std;
#define ll long long


ll solve(vector<pair<ll, ll>> &books, ll index, ll remainingAmount, vector<vector<ll>> &dp) {
    if (remainingAmount <= 0 || index >= books.size()) return 0;

    if (dp[index][remainingAmount] != -1) return dp[index][remainingAmount];
    //choose book, or don't choose book
    ll profit1 = 0;
    if (remainingAmount - books[index].first >= 0) profit1 = books[index].second + solve(books, index + 1, remainingAmount - books[index].first, dp); 
    ll profit2 = solve(books, index + 1, remainingAmount, dp);

    dp[index][remainingAmount] = max(profit1, profit2);
    return max(profit1, profit2);
}


int main() {
    ll n; ll p;
    cin >> n >> p;
    vector<ll> prices;
    vector<ll> pages;
    for (int i = 0; i < n; i ++) {
        ll x; cin >> x;
        prices.push_back(x);
    }
    for (int i = 0; i < n; i ++) {
        ll x; cin >> x;
        pages.push_back(x);
    }
    vector<pair<ll, ll>> books;
    for (int i = 0; i < n; i ++) {
        books.push_back({prices[i], pages[i]});
    }
    sort(books.begin(), books.end());
    cout << "started.." << endl;

    vector<vector<ll>> dp(books.size() + 1, vector<ll>(p + 1, -1));
    cout << solve(books, 0, p, dp) << endl;
}

//dp on index, amount left
