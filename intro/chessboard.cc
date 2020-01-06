#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define n 8

void printGrid(vector<vector<char>> &grid);
bool isSafe(vector<vector<char>> &grid, int row, int col);
int getWays(vector<vector<char>> &grid, int rowIndex);

int main() {
    vector<vector<char>> grid;
    char c;
    for (int i = 0; i < n; i ++) {
        vector<char> row;
        for (int j = 0; j < n; j ++) {
            cin >> c;
            row.push_back(c);
        }
        grid.push_back(row);
    }

    cout << getWays(grid, 0) << endl;

}

int getWays(vector<vector<char>> &grid, int rowIndex) {
    if (rowIndex == n) return 1;
    int ways = 0;
    for (int i = rowIndex; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (grid[i][j] == '*' || grid[i][j] == 'Q' || !isSafe(grid, i, j)) continue;
            grid[i][j] = 'Q';
            ways += getWays(grid, rowIndex + 1);
            grid[i][j] = '.';
        }
    }
    return ways;
}

bool isSafe(vector<vector<char>> &grid, int row, int col) {
    //check row
    for (int j = 0; j < n; j ++) if (grid[row][j] == 'Q') return false;
    //check col
    for (int i = 0; i < n; i ++) if (grid[i][col] == 'Q') return false;
    //check upper right diag
    for (int i = row, j = col; i >= 0 && j < n; i --, j ++) if (grid[i][j] == 'Q') return false;
    //check lower right diag
    for (int i = row, j = col; i < n && j < n; i ++, j ++) if (grid[i][j] == 'Q') return false;
    //check upper left diag
    for (int i = row, j = col; i >= 0 && j >= 0; i --, j --) if (grid[i][j] == 'Q') return false;
    //check lower left diag
    for (int i = row, j = col; i < n && j >= 0; i ++, j --) if (grid[i][j] == 'Q') return false;
    return true;
}

void printGrid(vector<vector<char>> &grid) {
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}