#include <bits/stdc++.h>

using namespace std;

#define ll long long

void printAdjList(ll vertices, vector<pair<ll, ll>> adjList[]) {
    for (ll i = 0; i < vertices; i ++) {
        cout << "index " << i << ": ";
        for (ll j = 0; j < adjList[i].size(); j ++) {
            cout << adjList[i][j].first << "," << adjList[i][j].second << " ";
        }
        cout << endl;
    }
}

int main() {
    ll vertices;
    ll edges;
    cin >> vertices >> edges;
    
    vector<pair<ll, ll>> adjList[vertices];
    vector<bool> processed(vertices, false);

    for (ll i = 0; i < edges; i ++) {
        ll from; ll to; ll weight;
        cin >> from >> to >> weight;
        from --; to --;
        adjList[from].push_back({to, weight});
    }

    ll distances[vertices];
    for (ll i = 0; i < vertices; i ++) distances[i] = INT_MAX;
    distances[0] = 0;

    //priority queue with pair first = cost, second = to node
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 0});

    while (!q.empty()) {
        ll cost = q.top().first;
        ll node = q.top().second;
        q.pop();
        //relax edges of node
        if (processed[node]) continue;
        processed[node] = true;
        for (auto neighbor : adjList[node]) {
            ll neighborNode = neighbor.first;
            ll weight = neighbor.second;
            if (distances[node] + weight < distances[neighborNode]) {
                distances[neighborNode] = distances[node] + weight;
                q.push({weight, neighborNode});
            }
        }
    }

    for (ll i = 0; i < vertices - 1; i ++) {
        cout << distances[i] << " ";
    }

    cout << distances[vertices - 1] << endl;

}