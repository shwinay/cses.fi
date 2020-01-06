#include <bits/stdc++.h>

using namespace std;

#define ll long long

pair<string, string> bfs(vector<vector<char>> &grid, pair<ll, ll> start, pair<ll, ll> end) {
    queue<pair<pair<ll,ll>, string>> q;
    q.push({start, ""});
    while (!q.empty()) {
        auto node = q.front(); q.pop();
        ll i = node.first.first; ll j = node.first.second;
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) continue;
        if (grid[i][j] == '#') continue;
        if (grid[i][j] == 'B') return {"YES", node.second};
        if (grid[i - 1][j] != '#') q.push({{i - 1, j}, node.second + "U"});
        if (grid[i + 1][j] != '#') q.push({{i + 1, j}, node.second + "D"});
        if (grid[i][j - 1] != '#') q.push({{i, j - 1}, node.second + "L"});
        if (grid[i][j + 1] != '#') q.push({{i, j + 1}, node.second + "R"});
        grid[i][j] = '#';
    }

    return {{-1, -1}, "NO"};
}

int main() {
    ll rows; ll cols;
    cin >> rows >> cols;
    vector<vector<char>> grid;
    pair<ll, ll> start;
    pair<ll, ll> end;
    for (ll i = 0; i < rows; i ++) {
        vector<char> row;
        char c;
        for (ll j = 0; j < cols; j ++) {
            cin >> c;
            if (c == 'A') start = {i, j};
            if (c == 'B') end = {i, j}; 
            row.push_back(c);
        }
        grid.push_back(row);
    }

    pair<string, string> result = bfs(grid, start, end);
    if (result.second == "NO") {
        cout << "NO" << endl;
        return 0;
    }
    cout << result.first << endl;
    cout << result.second.size() << endl;
    cout << result.second << endl;
}