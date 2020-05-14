#include <bits/stdc++.h>

using namespace std;

#define ll long long

void printList(vector<ll> list) {
    cout << "{ ";
    for (auto elem : list) cout << elem << " ";
    cout << " }";
}

int dfs(vector<ll> adjList[], ll node) {
    ll count = 1;
    vector<ll> children = adjList[node];
    for (auto child : children) {
        count += dfs(adjList, child);
    }
    return count;
}

int main() {
    ll nodes;
    cin >> nodes;
    vector<ll> adjList[nodes];
    for (ll i = 1; i < nodes; i ++) {
        ll currNode;
        cin >> currNode;
        adjList[currNode - 1].push_back(i);
    }

    // for (ll i = 0; i < nodes; i ++) {
    //     cout << i << ": ";
    //     printList(adjList[i]);
    //     cout << endl;
    // }
    for (ll i = 0; i < nodes; i ++) cout << dfs(adjList, i) - 1 << " ";
    cout << endl;
}