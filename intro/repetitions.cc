#include <bits/stdc++.h>

using namespace std;

int main() {
    //A,C,G,T
    string sequence;
    cin >> sequence;

    int maxSequence = 1;
    int currSequence = 1;
    char currChar = sequence[0];

    for (int i = 1; i < sequence.size(); i ++) {
        if (sequence[i] == currChar) {
            currSequence ++;
            maxSequence = max(maxSequence, currSequence);
        }
        else {
            currSequence = 1;
            currChar = sequence[i];
        }
    }

    cout << maxSequence << endl;
}