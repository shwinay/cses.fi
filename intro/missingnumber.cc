#include <bits/stdc++.h>

using namespace std;

int main() {
    uint32_t n;
    cin >> n;
    long long arr[n - 1];
    for (uint32_t i = 0; i < n - 1; i ++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    sort(arr, arr + n - 1);
    
    if (n == 2) {
        cout << (arr[0] == 1 ? 2 : 1) << endl;
        return 0;
    }

    for (uint32_t i = 1; i < n - 1; i ++) {
        if (arr[i] != arr[i - 1] + 1) {
            cout << arr[i] - 1 << endl;
            return 0;
        }
    }

    cout << n << endl;

}