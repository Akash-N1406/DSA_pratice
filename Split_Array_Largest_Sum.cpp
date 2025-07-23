/*410. Split Array Largest Sum
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.*/

#include <iostream>
#include <vector>
#include <numeric>   // For accumulate
#include <algorithm> // For max_element

using namespace std;

class Solution
{
private:
    bool canSplit(vector<int> &nums, int k, int mid)
    {
        int subarrays = 1;
        int currSum = 0;
        for (int num : nums)
        {
            if (currSum + num > mid)
            {
                subarrays++;
                currSum = num;
                if (subarrays > k)
                    return false;
            }
            else
            {
                currSum += num;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, k, mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    Solution sol;
    int result = sol.splitArray(nums, k);

    cout << "Minimized largest subarray sum: " << result << endl;
    return 0;
}
