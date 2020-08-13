#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll findMatchings(vector<vector<ll>> &adjList, ll currNode, bool canInclude, ll parent, vector<pair<ll, ll>> &dp) {
    ll keepNodeMatches = 0;
    ll discardNodeMatches = 0;

    if (canInclude && dp[currNode].first != -1) return dp[currNode].first;
    if (!canInclude && dp[currNode].second != -1) return dp[currNode].second;

    //don't include curr node edges
    for (auto neighbor : adjList[currNode]) {
        if (neighbor == parent) continue;
        discardNodeMatches += findMatchings(adjList, neighbor, true, currNode, dp);
    }

    //include curr node edges
    if (canInclude) {
        for (ll neighbor : adjList[currNode]) {
            if (neighbor == parent) continue;
            ll keepEdge = 1 + findMatchings(adjList, neighbor, false, currNode, dp);
            for (ll other : adjList[currNode]) {
                if (other == neighbor || other == parent) continue;
                keepEdge += findMatchings(adjList, other, true, currNode, dp);
            }
            keepNodeMatches = max(keepNodeMatches, keepEdge);
        }
    }

    if (canInclude) dp[currNode].first = max(keepNodeMatches, discardNodeMatches);
    if (!canInclude) dp[currNode].second = max(keepNodeMatches, discardNodeMatches);

    return max(keepNodeMatches, discardNodeMatches);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vector<vector<ll>> adjList(n, vector<ll>());
    for (ll i = 0; i < n - 1; i ++) {
        ll from; ll to;
        cin >> from >> to;
        from --; to --;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }
    
    //pair.first = (canInclude == true), pair.second = (canInclude == false)
    vector<pair<ll, ll>> dp(n, {-1, -1});
    // cout << "started.." << endl;
    cout << findMatchings(adjList, 0, true, -1, dp) << endl;
}

// 10
// 5 8
// 4 6
// 9 1
// 10 4
// 1 3
// 2 3
// 7 9
// 6 2
// 5 10