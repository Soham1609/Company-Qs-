#include<bits/stdc++.h>
using namespace std;

#define int long long

int func(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
    int ans = INT_MAX;
    vector<int> prefix(n);
    for (int i = 0; i < n; i++) {
        prefix[i] = arr[i];
        if (i > 0) prefix[i] += prefix[i - 1];
    }

    for (int i = 0; i < n; i++) {
        int firstSetMoves = 0;
        int secondSetMoves = 0;

        // if I consider this element as last element of first set

        // calculate number of moves for first set
        int len = i + 1;
        int median = arr[i / 2];
        firstSetMoves = (i / 2) * median - (i / 2 - 1 >= 0 ? prefix[i / 2 - 1] : 0);
        firstSetMoves += (prefix[i] - prefix[i / 2]) - ((i + 1) / 2) * median;

        // calculate number of moves for second set
        len = n - len;
        median = arr[i + (len + 1) / 2];
        secondSetMoves = ((len + 1) / 2) * median - (prefix[i + (len + 1) / 2] - prefix[i]);
        secondSetMoves += (prefix[n - 1] - prefix[i + (len + 1) / 2]) - (len / 2) * median;

        ans = min(ans, firstSetMoves + secondSetMoves);
    }
    return ans;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << func(arr, n) << endl;
    }
    return 0;
}

/*
INPUT
4
5
5 4 2 1 6
4
7 3 2 3
3
5 4 6
4
6 9 11 12
*/