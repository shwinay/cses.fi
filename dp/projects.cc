#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll n; cin >> n;
    vector<pair<ll, pair<ll, ll>>> jobs;
    while (n-- > 0) {
        ll start; ll end; ll profit;
        cin >> start >> end >> profit;
        jobs.push_back({start, {end, profit}});
    }

    sort(jobs.begin(), jobs.end(), [](const pair<ll, pair<ll, ll>> &a, const pair<ll, pair<ll, ll>> &b) {
        return a.second.first < b.second.first;
    });

    vector<ll> answers;
    for (auto i : jobs) answers.push_back(i.second.second);

    for (int i = 0; i < jobs.size(); i ++) {
        for (int j = 0; j < i; j ++) {
            if (jobs[i].first > jobs[j].second.first) {
                answers[i] = max(answers[i], jobs[i].second.second + answers[j]);
            }
        }
    }

    cout << *max_element(answers.begin(), answers.end()) << endl;


}