#include <iostream>
#define ll long long
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/discuss/interview-question/3850176/ION-or-Online-Assessment-or-DP

int longestValidSubsequence(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int index = 1; index < n; index++)
    {
        for (int prev = 0; prev < index; prev++)
        {
            if ((nums[index] ^ nums[prev]) == k)
            {
                dp[index] = max(dp[index], dp[prev] + 1);
            }
        }
    }

    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    return *max_element(dp.begin(), dp.end());
}

int main()
{
    // longest subsequence whose adjacent bitwise is equal to k

    int size;
    cin >> size;
    vector<int> nums;
    for (int i = 0; i < size; i++)
    {
        int input;
        cin >> input;
        nums.push_back(input);
    }
    int k;
    cin >> k;

    cout << longestValidSubsequence(nums, k);
    return 0;
}
