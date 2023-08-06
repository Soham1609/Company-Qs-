#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

vector<int> timeToLiveCache(int n, int q, vector<vector<int>>& data, vector<int>& queries) {
    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cache; // Min-heap to store end times
    unordered_map<int, int> startToEnd; // Map start time to end time

    // Sort data points based on start time
    sort(data.begin(), data.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    int dataIndex = 0;
    for (int queryTime : queries) {
        // Remove expired data points from the cache
        while (!cache.empty() && cache.top().first <= queryTime) {
            startToEnd.erase(cache.top().second);
            cache.pop();
        }

        // Add new data points to the cache
        while (dataIndex < n && data[dataIndex][0] <= queryTime) {
            int endTime = data[dataIndex][0] + data[dataIndex][1];
            cache.push(make_pair(endTime, data[dataIndex][0]));
            startToEnd[data[dataIndex][0]] = endTime;
            dataIndex++;
        }

        // Get the number of data points in the cache at the current query time
        result.push_back(cache.size());
    }

    return result;
}

int main() {
    int n = 4, q = 2;
    vector<vector<int>> data = {{5310825, 300}, {5311081, 101}, {5299871, 5239}, {5310025, 1081}};
    vector<int> queries = {5311088, 5299890};
    
    vector<int> result = timeToLiveCache(n, q, data, queries);

    // Output the result
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
