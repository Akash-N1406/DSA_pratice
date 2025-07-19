/*81. Search in Rotated Sorted Array II
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;

            if (nums[mid] == nums[low] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    cout << "Search 0 in {2,5,6,0,0,1,2}: "
         << (sol.search(nums1, target1) ? "Found" : "Not Found") << endl;

    // Test case 2
    vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    cout << "Search 3 in {2,5,6,0,0,1,2}: "
         << (sol.search(nums2, target2) ? "Found" : "Not Found") << endl;

    // Test case 3 (edge case with duplicates)
    vector<int> nums3 = {1, 0, 1, 1, 1};
    int target3 = 0;
    cout << "Search 0 in {1,0,1,1,1}: "
         << (sol.search(nums3, target3) ? "Found" : "Not Found") << endl;

    return 0;
}
