#include <bits/stdc++.h>

using namespace std;

#define ll long long

void printPath(vector<ll> &path) {
    bool foundFirst = false;
    ll index;
    for (ll i = 0; i < path.size(); i ++) {
        if (path[i] == path[path.size() - 1]) {
            index = i;
            break;
        }
    }
    cout << path.size() - index << endl;
    for (ll i = index; i < path.size() - 1; i ++) {
        if (!foundFirst && path[i] != path[path.size() - 1]) continue;
        foundFirst = true;
        cout << path[i] + 1 << " ";
    }
    cout << path[path.size() - 1] + 1 << endl;
}

bool dfs(ll node, ll parent, vector<ll> adjList[], vector<bool> &visited, vector<ll> path) {
    if (visited[node]) {
        path.push_back(node);
        printPath(path);
        return true;
    }
    visited[node] = true;
    path.push_back(node);
    vector<ll> neighbors = adjList[node];
    for (ll i = 0; i < neighbors.size(); i ++) {
        ll neighbor = neighbors[i];
        if (neighbor == parent) continue;
        if (dfs(neighbor, node, adjList, visited, path)) return true;
    }
    path.pop_back();
    return false;
}

int main() {
    ll nodes; ll edges;
    cin >> nodes >> edges;
    vector<ll> adjList[nodes];
    for (ll i = 0; i < edges; i ++) {
        ll from; ll to;
        cin >> from >> to;
        adjList[from - 1].push_back(to - 1);
        adjList[to - 1].push_back(from - 1);
    }
    vector<bool> visited(nodes, false);
    vector<ll> path;

    bool found = false;
    for (ll i = 0; i < nodes; i ++) {
        if (dfs(i, -1, adjList, visited, path)) {
            found = true;
            break;
        }
    }

    if (!found) cout << "IMPOSSIBLE" << endl;
}