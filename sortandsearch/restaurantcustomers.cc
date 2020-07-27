#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    //base cases
    if (n == 0 || n == 1) {
        cout << n << endl;
        return 0;
    }

    vector<pair<int, int> > customers;
    for (int i = 0; i < n; i ++) {
        int start; int end;
        cin >> start >> end;
        customers.push_back({start, 1});
        customers.push_back({end, -1});
    }

    sort(customers.begin(), customers.end());

    int maxCustomers = 1;
    int currCustomers = 0;

    for (int i = 0; i < customers.size(); i ++) {
        currCustomers += customers[i].second;
        maxCustomers = max(maxCustomers, currCustomers);        
    }

    cout << maxCustomers << endl;
}