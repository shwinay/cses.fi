#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int *nums = new int[n];
    int index = 0;
    for (int i = n; i > 0; i --) {
        if (i % 2 == 1) {
            nums[index] = i;
            index ++;
        }
    }
    for (int i = n; i > 0; i --) {
        if (i % 2 == 0) {
            nums[index] = i;
            index ++;
        }
    }

    for (int i = 1; i < n; i ++) {
        if (abs(nums[i] - nums[i - 1]) == 1) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i ++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}