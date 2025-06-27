/*2016. Maximum Difference Between Increasing Elements
Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int min_val = nums[0];
        int max_diff = -1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > min_val)
            {
                max_diff = max(max_diff, nums[i] - min_val);
            }
            else
            {
                min_val = nums[i];
            }
        }

        return max_diff;
    }
};

int main()
{
    Solution sol;

    // Sample test case
    vector<int> nums = {7, 1, 5, 4};

    int result = sol.maximumDifference(nums);
    cout << "Maximum difference: " << result << endl;

    return 0;
}
