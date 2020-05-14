#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll dfs(vector<pair<ll, ll>> adjList[], ll node, ll nodeCount) {
    vector<bool> visited(nodeCount, false);
    stack<pair<ll, ll>> dfsStack; //takes node, length of currPath
    ll minVal = LONG_LONG_MAX;
    dfsStack.push({node, 0});
    while (!dfsStack.empty()) {
        pair<ll, ll> currNode = dfsStack.top();
        dfsStack.pop();
        if (visited[currNode.first]) continue;
        for (auto neighbor : adjList[currNode.first]) {

        }
    }
}

int main() {
    ll nodes; ll edges;
    cin >> nodes >> edges;
    vector<pair<ll, ll>> adjList[nodes]; //maps from node to pair: {to node, cost to go from -> to}
    for (ll i = 0; i < edges; i ++) {
        ll from; ll to; ll cost;
        cin >> from >> to >> cost;
        adjList[from - 1].push_back({to - 1, cost});
    }

    //priority queue ordered by minimum cost nodes
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        ll node = pq.top().second;
        pq.pop();
        if (processed[node]) continue;
        processed[node] = true;
        for (auto n : adjList[node]) {
            ll neighbor = n.first;
            ll cost = n.second;
            paths[neighbor] = min(paths[node] + cost, paths[neighbor]);
            pq.push({paths[neighbor], neighbor});
        }
    }

    for (ll i = 0; i < paths.size() - 1; i ++) {
        cout << paths[i] << " ";
    }
    cout << paths[paths.size() - 1] << endl;
}