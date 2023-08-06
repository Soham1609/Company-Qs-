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

// https://leetcode.com/discuss/interview-question/3849027/ION-Group-QAw
int solution(const vector<vector<int>> &g, int k)
{
    const int m = g.size(), n = g[0].size();
    if (g[0][0] || g[m - 1][n - 1])
    {
        return -1;
    }
    vector<set<int>> r(m), c(n);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (g[i][j] == 0)
            {
                r[i].insert(j);
                c[j].insert(i);
            }
        }
    }
    vector<vector<int>> d(m, vector<int>(n, -1));
    r[0].erase(0);
    c[0].erase(0);
    d[0][0] = 0;
    queue<pair<int, int>> q;
    for (q.push({0, 0}); !q.empty() && d[m - 1][n - 1] < 0;)
    {
        const int x = q.front().first, y = q.front().second;
        q.pop();
        for (auto t = r[x].lower_bound(y - k); t != r[x].end() && *t <= y + k;)
        {
            d[x][*t] = d[x][y] + 1;
            q.push({x, *t});
            c[*t].erase(x);
            r[x].erase(t++);
        }
        for (auto t = c[y].lower_bound(x - k); t != c[y].end() && *t <= x + k;)
        {
            d[*t][y] = d[x][y] + 1;
            q.push({*t, y});
            r[*t].erase(y);
            c[y].erase(t++);
        }
    }
    return d[m - 1][n - 1];
}

int main()
{
    cout << solution({{0, 0}, {1, 0}}, 2) << endl;
    return 0;
}
int main()
{
    ios
        tc
        BADjX();
    return 0;
}