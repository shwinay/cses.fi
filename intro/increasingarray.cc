#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int x;
    cin >> n;
    int *nums = new int[n];

    for (int i = 0; i < n; i ++) {
        cin >> x;
        nums[i] = x;
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    long long count = 0;
    for (int i = 1; i < n; i ++) {
        if (nums[i] < nums[i - 1]) {
            count += abs(nums[i] - nums[i - 1]);
            nums[i] = nums[i - 1];
        }
    }
    cout << count << endl;
}