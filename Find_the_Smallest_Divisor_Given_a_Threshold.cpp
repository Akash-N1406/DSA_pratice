/*1283. Find the Smallest Divisor Given a Threshold
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.*/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool isPossible(vector<int> &nums, int mid, int threshold)
    {
        int total = 0;
        for (int num : nums)
        {
            total += ceil(double(num) / mid);
        }
        return total <= threshold;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1;
        int high = *(max_element(nums.begin(), nums.end()));
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, mid, threshold))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    int result = sol.smallestDivisor(nums, threshold);

    cout << "Smallest Divisor: " << result << endl;

    return 0;
}
