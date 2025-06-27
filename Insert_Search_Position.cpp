/*35. Insert Search Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};

    int target1 = 5;
    int target2 = 2;
    int target3 = 7;
    int target4 = 0;

    cout << "Index for " << target1 << ": " << sol.searchInsert(nums, target1) << endl;
    cout << "Index for " << target2 << ": " << sol.searchInsert(nums, target2) << endl;
    cout << "Index for " << target3 << ": " << sol.searchInsert(nums, target3) << endl;
    cout << "Index for " << target4 << ": " << sol.searchInsert(nums, target4) << endl;

    return 0;
}