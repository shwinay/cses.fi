#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<char, int> *charMap = new unordered_map<char, int>();
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i ++) {
        char c= s[i];
        int charCount = 1;
        if (charMap->count(c) == 1) charCount += (*charMap)[c];
        (*charMap)[c] = charCount;
    }

    bool hitOdd = false;
    for (auto elem : (*charMap)) {
        if (elem.second % 2 == 1) {
            if (!hitOdd) hitOdd = true;
            else {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
    }

    char *palindrome = new char[s.size()];
    int leftIndex = 0;
    int rightIndex = s.size() - 1;
    for (auto elem : (*charMap)) {
        if (elem.second % 2 == 0) {
            int count = elem.second;
            while (count > 0) {
                palindrome[rightIndex] = elem.first;
                palindrome[leftIndex] = elem.first;
                rightIndex --; leftIndex ++;
                count -= 2;
            }
        }
        else {
            int count = elem.second;
            int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
            palindrome[midIndex] = elem.first;
            for (int i = 0; i < (count - 1) / 2; i ++) {
                palindrome[midIndex + i + 1] = elem.first;
                palindrome[midIndex - i - 1] = elem.first;
            }
        }
    }

    for (int i = 0; i < s.size(); i ++) {
        cout << palindrome[i];
    }

    cout << endl;
}