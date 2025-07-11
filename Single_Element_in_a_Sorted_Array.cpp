/*Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 1)
                mid--;
            if (nums[mid] == nums[mid + 1])
            {
                low = mid + 2;
            }
            else
            {
                high = mid;
            }
        }
        return nums[low];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};

    int result = sol.singleNonDuplicate(nums);
    cout << "The single non-duplicate element is: " << result << endl;

    return 0;
}
