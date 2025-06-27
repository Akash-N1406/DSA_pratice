/*485. Max Consecutive Ones
Given a binary array nums, return the maximum number of consecutive 1's in the array.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxCount = 0;
        int currentCount = 0;
        for (int num : nums)
        {
            if (num == 1)
            {
                ++currentCount;
            }
            else
            {
                maxCount = max(maxCount, currentCount);
                currentCount = 0;
            }
        }
        return max(maxCount, currentCount);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1}; // Example input
    int result = sol.findMaxConsecutiveOnes(nums);
    cout << "Maximum number of consecutive 1s: " << result << endl;
    return 0;
}