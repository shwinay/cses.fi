#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll n; ll m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adjList(n, vector<pair<ll, ll>>());

    while(m-- > 0) {
        ll from; ll to; ll cost;
        cin >> from >> to >> cost;
        from --; to --;
        adjList[from].push_back({to, cost});
    }

    //holds pairs that represent {cost, node}
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> distances(n, LLONG_MAX);
    distances[0] = 0;
    vector<bool> visited(n, false);

    pq.push({0, 0});
    while (!pq.empty()) {
        auto curr = pq.top();
        auto currCost = curr.first; auto currNode = curr.second;
        pq.pop();
        if (visited[currNode]) continue;
        visited[currNode] = true;
        for (auto neighbor : adjList[currNode]) {
            if (currCost + neighbor.second < distances[neighbor.first]) {
                distances[neighbor.first] = currCost + neighbor.second;
                pq.push({currCost + neighbor.second, neighbor.first});
            }
        }
    }

    for (auto d : distances) cout << d << " ";
    cout << endl;

}