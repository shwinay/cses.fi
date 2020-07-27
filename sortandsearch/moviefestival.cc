#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    if (n == 0 || n == 1) {
        cout << n << endl;
        return 0;
    }    

    vector<pair<int, int>> movieTimings;
    while (n-- > 0) {
        int start; int end;
        cin >> start >> end;
        movieTimings.push_back({start, end});
    }

    sort(movieTimings.begin(), movieTimings.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });

    int movies = 1;
    int currEnd = movieTimings[0].second;

    for (int i = 1; i < movieTimings.size(); i ++) {
        auto currMovie = movieTimings[i];
        if (currMovie.first < currEnd) continue;
        movies ++;
        currEnd = currMovie.second;
    }

    cout << movies << endl;
}