/*75. SORT COLORS
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for (int num : nums) {
            if (num == 0) count[0]++;
            else if (num == 1) count[1]++;
            else count[2]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (count[0] != 0) {
                nums[i] = 0;
                count[0]--;
            }
            else if (count[1] != 0) {
                nums[i] = 1;
                count[1]--;
            }
            else {
                nums[i] = 2;
                count[2]--;
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