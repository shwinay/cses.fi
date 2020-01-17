#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool bfs(vector<ll> adjList[], vector<ll> &nodeColors, ll i) {
    queue<ll> nodeQueue;
    nodeQueue.push(i);
    nodeColors[i] = 1;
    while (!nodeQueue.empty()) {
        ll node = nodeQueue.front();
        nodeQueue.pop();
        ll currColor = nodeColors[node];
        ll nextColor = currColor == 1 ? 2 : 1;
        vector<ll> neighbors = adjList[node];
        for (ll i = 0; i < neighbors.size(); i ++) {
            ll neighbor = neighbors[i];
            if (nodeColors[neighbor] != 0) {
                if (nodeColors[neighbor] != nextColor) return false;
            }
            else {
                nodeColors[neighbor] = nextColor;
                nodeQueue.push(neighbor);
            }
        }
    }
    return true;
}

int main() {
    ll nodes; ll edges;
    cin >> nodes >> edges;
    vector<ll> adjList[nodes];
    ll currColor = 1;
    vector<ll> nodeColors(nodes, 0);

    for (ll i = 0; i < edges; i ++) {
        ll from; ll to;
        cin >> from >> to;
        adjList[from - 1].push_back(to - 1);
        adjList[to - 1].push_back(from - 1);
    }

    for (ll i = 0; i < nodeColors.size(); i ++) {
        if (nodeColors[i] == 0) {
            if (!bfs(adjList, nodeColors, i)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (ll i = 0; i < nodeColors.size(); i ++) {
        cout << nodeColors[i] << " ";
    }
    cout << endl;
}