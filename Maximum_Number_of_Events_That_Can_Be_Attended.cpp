/*1353. Maximum Number of Events That Can Be Attended
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, n = events.size(), day = 0, res = 0;
        while (i < n || !pq.empty())
        {
            if (pq.empty())
                day = events[i][0];
            while (i < n && events[i][0] <= day)
            {
                pq.push(events[i][1]);
                i++;
            }
            while (!pq.empty() && pq.top() < day)
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                pq.pop();
                res++;
                day++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}};
    int result = sol.maxEvents(events);
    cout << result << endl;
    return 0;
}
