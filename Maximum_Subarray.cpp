/*53. Maximum Subarray
Given an integer array nums, find the subarray with the largest sum, and return its sum.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            sum = max(nums[i], sum + nums[i]);
            result = max(result, sum);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution sol;
    int maxSum = sol.maxSubArray(nums);

    cout << "Maximum subarray sum is: " << maxSum << endl;

    return 0;
}
