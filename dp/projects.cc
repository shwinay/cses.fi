#include <bits/stdc++.h>

using namespace std;

#define ll long long

void printJobs(vector<tuple<ll, ll, ll>> &jobs) {
    for (auto job : jobs) {
        cout << "(" << get<0>(job) << ", " << get<1>(job) << ", " << get<2>(job) << ")" << endl;
    }
}
string jobStr(tuple<ll, ll, ll> &job) {
    return "(" + to_string(get<0>(job)) + ", " + to_string(get<1>(job)) + ", " + to_string(get<2>(job)) + ")";
}

ll getMaxProfit(vector<tuple<ll, ll, ll>> &jobs, ll index, ll currTime, ll currProfit, vector<bool> &isReady, vector<ll> &answers) {
    
    if (index >= jobs.size()) return currProfit;
    auto currJob = jobs[index];
    bool canPick = get<0>(currJob) > currTime;
    if (canPick) {
        if (isReady[index]) {
            return answers[index];
        }
        else {
            ll answer = max(getMaxProfit(jobs, index + 1, currTime, currProfit, isReady, answers), 
                            getMaxProfit(jobs, index + 1, get<1>(currJob), currProfit + get<2>(currJob), isReady, answers));
            isReady[index] = true;
            answers[index] = answer;
            return answer;
        }
    }
    else {
        return getMaxProfit(jobs, index + 1, currTime, currProfit, isReady, answers);
    }
}

int main() {
    ll n;
    vector<tuple<ll, ll, ll>> jobs;
    cin >> n;
    for (ll i = 0; i < n; i ++) {
        ll start; ll end; ll profit;
        cin >> start >> end >> profit;
        auto job = make_tuple(start, end, profit);
        jobs.push_back(job); 
    }
    sort(jobs.begin(), jobs.end(), [](auto &left, auto &right) {
        return get<1>(left) < get<1>(right);
    });
    vector<ll> answers(jobs.size(), 0);
    vector<bool> isReady(jobs.size(), false);
    cout << getMaxProfit(jobs, 0, 0, 0, isReady, answers) << endl;
}
