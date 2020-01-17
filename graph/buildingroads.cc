#include <bits/stdc++.h>

using namespace std;

#define ll long long

void connectComponent(vector<ll> adjList[], bool visited[], ll node) {
    if (visited[node]) return;
    visited[node] = true;
    vector<ll> neighbors = adjList[node];
    for (ll i = 0; i < neighbors.size(); i ++) {
        connectComponent(adjList, visited, neighbors[i]);
    }
}

int main() {
    ll cities; ll roads;
    cin >> cities >> roads;
    vector<ll> adjList[cities];
    for (ll i = 0; i < roads; i ++) {
        ll from; ll to;
        cin >> from >> to;
        from --; to --;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    bool visited[cities];
    for (ll i = 0; i < cities; i ++) visited[i] = false;

    ll count = 0;
    vector<ll> componentHeads;
    for (ll i = 0; i < cities; i ++) {
        if (visited[i]) continue;
        connectComponent(adjList, visited, i);
        count ++;
        componentHeads.push_back(i);
    }

    cout << count - 1 << endl;
    for (ll i = 1; i < componentHeads.size(); i ++) {
        cout << componentHeads[i - 1] + 1 << " " << componentHeads[i] + 1 << endl;
    }
}