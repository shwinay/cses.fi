#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll nodes; ll edges;
    cin >> nodes >> edges;
    vector<pair<ll, ll>> adjList[nodes]; //maps from node to pair: {to node, cost to go from -> to}
    vector<ll> processed(nodes, false);
    vector<ll> paths(nodes, LONG_LONG_MAX);
    paths[0] = 0;
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