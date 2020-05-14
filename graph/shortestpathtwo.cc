#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF LONG_LONG_MAX

void printGrid(vector<vector<ll>> &grid) {
    cout << endl;
    for (ll i = 0; i < grid.size(); i ++) {
        for (ll j = 0; j < grid[i].size(); j ++) {
            if (grid[i][j] == INF) cout << "I" << " ";
            else cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ll nodes; ll edges; ll queries;
    cin >> nodes >> edges >> queries;

    //set up grid
    vector<vector<ll>> grid(nodes, vector<ll>(nodes, INF));
    for (ll i = 0; i < nodes; i ++) grid[i][i] = 0;
    for (ll i = 0; i < edges; i ++) {
        ll from; ll to; ll cost;
        cin >> from >> to >> cost;
        from --; to --;
        grid[from][to] = min(grid[from][to], cost);
        grid[to][from] = min(grid[from][to], cost);
    }

    //run floyd warshall
    for (ll intermediate = 0; intermediate < nodes; intermediate ++) {
        for (ll i = 0; i < grid.size(); i ++) {
            for (ll j = 0; j < grid.size(); j ++) {
                if (grid[i][intermediate] != INF && grid[intermediate][j] != INF) {
                    grid[i][j] = min(grid[i][j], grid[i][intermediate] + grid[intermediate][j]);
                }
            }
        }
    }

    //process queries
    for (ll i = 0; i < queries; i ++) {
        ll from; ll to;
        cin >> from >> to;
        ll answer = grid[from - 1][to - 1];
        cout << (answer == INF ? -1 : answer) << endl;
    }
}