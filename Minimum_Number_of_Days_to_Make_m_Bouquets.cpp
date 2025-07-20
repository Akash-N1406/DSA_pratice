/*1482. Minimum Number of Days to Make m Bouquets
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool isPossible(vector<int> &bloomDay, int mid, int m, int k)
    {
        int count = 0;
        int bouq = 0;
        for (int num : bloomDay)
        {
            if (num <= mid)
            {
                count++;
            }
            else
            {
                bouq += count / k;
                count = 0;
            }
        }
        bouq += count / k;
        return bouq >= m;
    }

public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long val = m * 1LL * k * 1LL;
        if (val > bloomDay.size())
            return -1;
        int low = *(min_element(bloomDay.begin(), bloomDay.end()));
        int high = *(max_element(bloomDay.begin(), bloomDay.end()));
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, mid, m, k))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    int result = sol.minDays(bloomDay, m, k);
    cout << "Minimum number of days: " << result << endl;

    return 0;
}
