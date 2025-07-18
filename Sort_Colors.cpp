/*75. SORT COLORS
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
                mid++;
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Before sorting: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    sol.sortColors(nums);

    cout << "After sorting: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
