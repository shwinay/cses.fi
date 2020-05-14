#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll nodes; ll edges;
    cin >> nodes >> edges;
    vector<pair<ll, ll>> adjList[nodes];
    for (ll i = 0; i < edges; i ++) {
        ll from; ll to; ll weight;
        cin >> from >> to >> weight;
        adjList[from - 1].push_back({to - 1, weight});
    }

    vector<ll> distances(nodes, LONG_LONG_MIN);
    distances[0] = 0;
    //run n - 1 times
    for (ll i = 0; i < nodes - 1; i ++) {
        for (ll node = 0; node < nodes; node ++) {
            vector<pair<ll, ll>> edgeList = adjList[node];
            for (pair<ll, ll> edge : edgeList) {
                distances[edge.first] = max(distances[edge.first], distances[node] + edge.second);
            }
        }
    }

    ll answer = distances[distances.size() - 1];

    for (ll node = 0; node < nodes; node ++) {
        vector<pair<ll, ll>> edgeList = adjList[node];
        for (pair<ll, ll> edge : edgeList) {
            ll prev = distances[edge.first];
            distances[edge.first] = max(distances[edge.first], distances[node] + edge.second);
            if (prev != distances[edge.first]) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    cout << answer << endl;
}