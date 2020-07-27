#include <bits/stdc++.h>

using namespace std;

int main() {
	int numTickets; int numCustomers;
	cin >> numTickets >> numCustomers;
	multiset<int, greater<int> > tickets;
	for (int i = 0; i < numTickets; i ++) {
		int ticket; cin >> ticket;
		tickets.insert(ticket);
	}	
	
	for (int i = 0; i < numCustomers; i ++) {
		int customer; cin >> customer;
		auto it = tickets.lower_bound(customer);
		if (it == tickets.end()) cout << "-1" << endl;
		else {
			cout << *it << endl;
			tickets.erase(it);
		}
	}

}
