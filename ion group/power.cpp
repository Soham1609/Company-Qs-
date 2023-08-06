#include <iostream>
#define ll long long
#include <vector>
#include <bits/stdc++.h>
#define tc int t;cin>>t;while(t--)
#define ll long long
#define ios  cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
        
const int N = 1e5+10;
vector<int>g[N];
bool vis[N];

#define fora(mp) for(auto x :mp);
//  https://leetcode.com/discuss/interview-question/3857016/Ion-Group-or-On-campus-2023
long long solution(const vector<int>& nums) {
    const int n = nums.size();
    vector<long long> dp(2);
    dp[1] = nums[0];
    for (int i = 1; i < n; ++i) {
        dp = {max(dp[0], dp[1]), dp[0] + nums[i]};
    }
    return max(dp[0], dp[1]);
}

int main() {
    cout << solution({3, 3, 3, 4, 4, 1, 8}) << endl;
    return 0;
}