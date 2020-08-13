#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll n; cin >> n;

    //{time, {isStart, customerId}}
    vector<pair<ll, pair<bool, ll>>> rooms;
    for (int i = 0; i < n; i ++) {
        ll start; ll end;
        cin >> start >> end;
        rooms.push_back({start, {true, i}});
        rooms.push_back({end, {false, i}});
    }

    sort(rooms.begin(), rooms.end());

    vector<ll> res(n, -1);
    //we want to store occupied rooms in sorted order, as well as who is occupying them.
    //when a customer goes out, release occupied room
    set<ll> occupiedRooms;
    
    //stores prev out time, room
    pair<ll, ll> prevOut = {-1, -1};
    for (auto elem : rooms) {
        ll currTime = elem.first;
        bool goingIn = elem.second.first;
        ll customerId = elem.second.second;

        if (goingIn) {
            ll currRoom = -1;
            for (ll i = 1; i <= n; i ++) {
                if (occupiedRooms.count(i) == 0) {
                    if (currTime == prevOut.first && i == prevOut.second) continue;
                    currRoom = i;
                    break;
                }
            }

            occupiedRooms.insert(currRoom);
            res[customerId] = currRoom;
        } 
        else {
            ll currRoom = res[customerId];
            prevOut = {currTime, currRoom};
            occupiedRooms.erase(currRoom);
        }
    }

    cout << *max_element(res.begin(), res.end()) << endl;
    for (auto elem : res) cout << elem << " ";
    cout << endl;
    
}