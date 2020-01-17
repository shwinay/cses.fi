#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll computers; ll connections;
    cin >> computers >> connections;
    vector<ll> adjList[computers];
    for (ll i = 0; i < connections; i ++) {
        ll from; ll to;
        cin >> from >> to;
        adjList[from - 1].push_back(to - 1);
        adjList[to - 1].push_back(from - 1);
    }

    bool visited[computers];
    for (ll i = 0; i < computers; i ++) visited[i] = false;
    queue<pair<ll, pair<string, ll>>> bfsqueue;
    bfsqueue.push({0, {"", 0}});

    while (!bfsqueue.empty()) {
        pair<ll, pair<string, ll>> node = bfsqueue.front();
        bfsqueue.pop();
        if (node.first == computers - 1) {
            cout << node.second.second + 1 << endl;
            cout << node.second.first << to_string(computers) << endl;
            return 0;
        }
	if (visited[node.first]) continue;
	visited[node.first] = true;
        for (ll i = 0; i < adjList[node.first].size(); i ++) {
            ll neighbor = adjList[node.first][i];
            bfsqueue.push({neighbor, {node.second.first + to_string(node.first + 1) + " ", node.second.second + 1}});
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
