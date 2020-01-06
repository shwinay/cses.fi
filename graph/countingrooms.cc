#include <bits/stdc++.h>

using namespace std;

#define ll long long

void printGrid(vector<vector<char>> &grid) {
    for (ll i = 0; i < grid.size(); i ++) {
        for (ll j = 0; j < grid[i].size(); j ++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void dfs(vector<vector<char>> &grid, ll i, ll j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
    if (grid[i][j] != '.') return;
    grid[i][j] = '#';
    vector<pair<ll,ll>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (auto coords : directions) {
        dfs(grid, i + coords.first, j + coords.second);
    }
}

int main() {
    ll rows; ll cols;
    cin >> rows >> cols;
    vector<vector<char>> grid;
    for (ll i = 0; i < rows; i ++) {
        vector<char> row;
        char c;
        for (ll j = 0; j < cols; j ++) {
            cin >> c;
            row.push_back(c);
        }
        grid.push_back(row);
    }

    ll rooms = 0;
    for (ll i = 0; i < grid.size(); i ++) {
        for (ll j = 0; j < grid[i].size(); j ++) {
            char c = grid[i][j];
            if (c == '.') {
                dfs(grid, i, j);
                rooms ++;
                cout << endl;
            }
        }
    }

    cout << rooms << endl;
}