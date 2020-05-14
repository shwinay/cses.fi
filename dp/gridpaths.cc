#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define LCONST 1000000007

ll getPaths(vector<vector<char>> &grid, int i, int j, vector<vector<ll>> &answers) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;
    if (grid[i][j] == '*') return 0;
    if (i == 0 && j == 0) return 1;

    ll leftAns; ll upAns;
    if (j - 1 >= 0 && answers[i][j - 1] > -1) leftAns = answers[i][j - 1];
    else {
        leftAns = getPaths(grid, i, j - 1, answers);
        if (j - 1 >= 0) answers[i][j - 1] = leftAns;
    }

    if (i - 1 >= 0 && answers[i - 1][j] > -1) upAns = answers[i - 1][j];
    else {
        upAns = getPaths(grid, i - 1, j, answers);
        if (i - 1 >= 0) answers[i - 1][j] = upAns;
    }

    answers[i][j] = (upAns % LCONST + leftAns % LCONST) % LCONST;

    return answers[i][j];
}

int main() {
    int n; cin >> n;
    vector<vector<char>> grid;
    for (int i = 0; i < n; i ++) {
        vector<char> row;
        char c;
        for (int j = 0; j < n; j ++) {
            cin >> c;
            row.push_back(c);
        }
        grid.push_back(row);
    }

    vector<vector<ll>> answers;
    for (int i = 0; i < n; i ++) {
        vector<ll> row(n, -1);
        answers.push_back(row);
    }

    cout << getPaths(grid, grid.size() - 1, grid[0].size() - 1, answers) % LCONST << endl;
}