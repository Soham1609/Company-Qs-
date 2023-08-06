#include <iostream>
#define ll long long
#include <vector>
#include <bits/stdc++.h>
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define ios                     \
    cin.sync_with_stdio(false); \
    cin.tie(0);                 \
    cout.tie(0);
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

#define fora(mp)      \
    for (auto x : mp) \
        ;
// https://leetcode.com/discuss/interview-question/3848806/ION-Group-OA-or-On-Campus-2023
long long solution(const string &s)
{
    const int n = s.length();
    vector<int> z(n);
    long long r = n;
    for (int i = 1, left = 0, right = 0; i < n; ++i)
    {
        if (i <= right && z[i - left] <= right - i)
        {
            z[i] = z[i - left];
        }
        else
        {
            for (z[i] = max(0, right - i + 1); i + z[i] < n && s[i + z[i]] == s[z[i]]; ++z[i]);
        }
        if (i + z[i] - 1 > right)
        {
            left = i;
            right = i + z[i] - 1;
        }
        r += z[i];
    }
    return r;
}

int main()
{
    cout << solution("abcdabca") << endl;
    return 0;
}