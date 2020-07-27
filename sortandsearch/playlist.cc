#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<ll> songs;
    while (n-- > 0) {
        ll song; cin >> song;
        songs.push_back(song);
    }

    ll left = 0;
    ll right = 0;

    set<ll> songSet;
    int maxSongs = 0;
    while (right < songs.size()) {
        int currElem = songs[right];
        if (songSet.count(currElem) == 0) {
            songSet.insert(currElem);
            right ++;
            maxSongs = max((ll) maxSongs, (ll) songSet.size());
        } else {
            while (songSet.count(currElem) != 0) {
                songSet.erase(songs[left]);
                left ++;
            }
        }
    }

    cout << maxSongs << "\n";
}