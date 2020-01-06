#include <bits/stdc++.h>

using namespace std;

void generatePermutations(string s, set<string> *wordSet, string currWord, bool *used);

int main() {
    string s;
    cin >> s;
    set<string> *wordSet = new set<string>();
    bool *used = new bool[s.size()];
    for (int i = 0; i < s.size(); i ++) used[i] = false;
    generatePermutations(s, wordSet, "", used);
    cout << wordSet->size() << endl;
    for (auto elem : (*wordSet)) {
        cout << elem << endl;
    }
}

void generatePermutations(string s, set<string> *wordSet, string currWord, bool *used) {
    if (currWord.size() == s.size()) {
        wordSet->insert(currWord);
        return;
    }
    for (int i = 0; i < s.size(); i ++) {
        if (used[i]) continue;
        used[i] = true;
        generatePermutations(s, wordSet, currWord + s[i], used);
        used[i] = false;
    }
}
