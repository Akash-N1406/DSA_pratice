/*1011. Capacity To Ship Packages Within D Days
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.*/

#include <iostream>
#include <vector>
#include <numeric>   // for accumulate
#include <algorithm> // for max_element

using namespace std;

class Solution
{
public:
    bool canShip(const vector<int> &weights, int capacity, int days)
    {
        int dayCount = 1;
        int currentLoad = 0;

        for (int weight : weights)
        {
            if (currentLoad + weight > capacity)
            {
                dayCount++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }

        return dayCount <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int result = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (canShip(weights, mid, days))
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;

    // Example input
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    int result = solution.shipWithinDays(weights, days);
    cout << "Minimum capacity to ship within " << days << " days is: " << result << endl;

    return 0;
}
