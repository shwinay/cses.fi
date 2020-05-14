#include <bits/stdc++.h>

using namespace std;

int editDistance(string &s1, string &s2, int index1, int index2, vector<vector<int>> &answers);

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    vector<vector<int>> answers(s1.size(), vector<int>(s2.size(), -1));
    cout << editDistance(s1, s2, s1.size() - 1, s2.size() - 1, answers) << endl;
}

int editDistance(string &s1, string &s2, int index1, int index2, vector<vector<int>> &answers) {
    //base cases
    if (index1 == 0 && index2 == 0) return s1[0] == s2[0] ? 0 : 1;
    if (index1 == 0) return s1[index1] == s2[index2] ? index2 : index2 + 1;
    if (index2 == 0) return s1[index1] == s2[index2] ? index1 : index1 + 1;

    //both chars same
    if (s1[index1] == s2[index2]) {
        if (answers[index1 - 1][index2 - 1] != -1) return answers[index1 - 1][index2 - 1];
        auto answer = editDistance(s1, s2, index1 - 1, index2 - 1, answers);
        answers[index1 - 1][index2 - 1] = answer;
        return answer;
    }
    
    int edited; int leftDeleted; int rightDeleted;
    if (answers[index1 - 1][index2 - 1] != -1) edited = 1 + answers[index1 - 1][index2 - 1];
    else {
        auto answer = editDistance(s1, s2, index1 - 1, index2 - 1, answers);
        answers[index1 - 1][index2 - 1] = answer;
        edited = answer + 1;
    }
    
    if (answers[index1 - 1][index2] != -1) leftDeleted = 1 + answers[index1 - 1][index2];
    else {
        auto answer = editDistance(s1, s2, index1 - 1, index2, answers);
        answers[index1 - 1][index2] = answer;
        leftDeleted = answer + 1;
    }
    if (answers[index1][index2 - 1] != -1) rightDeleted = 1 + answers[index1][index2 - 1];
    else {
        auto answer = editDistance(s1, s2, index1, index2 - 1, answers);
        answers[index1][index2 - 1] = answer;
        rightDeleted = answer + 1;
    }
    answers[index1][index2] = min(edited, min(leftDeleted, rightDeleted));
    return min(edited, min(leftDeleted, rightDeleted));
}
