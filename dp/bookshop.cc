#include <bits/stdc++.h>

using namespace std;

#define ll long long

int getMaxPages(vector<int> &prices, vector<int> &pages, int index, int currPrice, vector<vector<int>> &answers) {
    if (currPrice <= 0 || index >= prices.size()) return 0;
    
    //select the item
    int selectedPages = 0;
    if (currPrice - prices[index] >= 0) {
        if (index + 1 < pages.size() && answers[currPrice - prices[index]][index + 1] != -1) {
            //cout << "triggered!" << endl;
            selectedPages = pages[index] + answers[currPrice - prices[index]][index + 1];
        } else {
            selectedPages = pages[index] + getMaxPages(prices, pages, index + 1, currPrice - prices[index], answers);
            if (index + 1 < pages.size()) answers[currPrice - prices[index]][index + 1] = selectedPages - pages[index];
        }
    }

    //don't select the item
    int unselectedPages = 0;
    if (index + 1 < pages.size() && answers[currPrice][index + 1] != -1) {
        //cout << "t!" << endl;
        unselectedPages = answers[currPrice][index + 1];
    }
    else {
        unselectedPages = getMaxPages(prices, pages, index + 1, currPrice, answers);
        if (index + 1 < pages.size()) answers[currPrice][index + 1] = unselectedPages;
    }

    answers[currPrice][index] = max(selectedPages, unselectedPages);
    return max(selectedPages, unselectedPages);

}

int main() {
    int numBooks; int maxPrice;
    cin >> numBooks >> maxPrice;
    vector<int> prices; vector<int> pages;
    for (int i = 0; i < numBooks; i ++) {
        int price; cin >> price;
        prices.push_back(price);
    }
    for (int i = 0; i < numBooks; i ++) {
        int page; cin >> page;
        pages.push_back(page);
    }

    //numItems by maxPrice
    //each price has an answer for a given index
    vector<vector<int>> answers(maxPrice + 1, vector<int>(pages.size(), -1));
    cout << getMaxPages(prices, pages, 0, maxPrice, answers) << endl;
}