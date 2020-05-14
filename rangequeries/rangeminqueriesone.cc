#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> buildTree(vector<int> &nums); 
int minRangeQuery(vector<int> &tree, int lower, int upper);

//ranges are 0-indexed, tree is 1-indexed

int main() {
    int numElems; int numQueries;
    cin >> numElems >> numQueries;
    vector<int> nums;
    for (int i = 0; i < numElems; i ++) {
        int elem; cin >> elem;
        nums.push_back(elem);
    }

    auto tree = buildTree(nums);
    tree[0] = INT_MAX;

    vector<int> answers;
    for(int i = 0; i < numQueries; i ++) {
        int lower; int upper;
        cin >> lower >> upper;
        answers.push_back(minRangeQuery(tree, lower - 1, upper));
    }

    for (auto a : answers) cout << a << endl;
}

//range query [inclusive, exclusive)
int minRangeQuery(vector<int> &tree, int lower, int upper) {
    int minVal = INT_MAX;
    lower += tree.size() / 2;
    upper += tree.size() / 2;
    while (lower < upper) {
        if (lower % 2 == 1) {
            minVal = min(minVal, tree[lower]);
            lower ++;
        }        
        if (upper % 2 == 1) {
            upper --;
            minVal = min(minVal, tree[upper]);
        }
        lower /= 2;
        upper /= 2;
    }
    return minVal;
}

vector<int> buildTree(vector<int> &nums) {
    vector<int> tree(nums.size() * 2, 0);
    
    //fill in back half of elems
    for (int i = nums.size(); i < tree.size(); i ++) {
        tree[i] = nums[i - nums.size()];
    }

    //fill in tree
    for (int i = nums.size() - 1; i >= 1; i --) {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
    return tree;
}
