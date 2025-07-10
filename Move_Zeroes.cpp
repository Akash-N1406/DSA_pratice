/*283. Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                if (i != k)
                {
                    nums[k] = nums[i];
                    nums[i] = 0;
                }
                k++;
            }
        }
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Before moving zeroes: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    Solution sol;
    sol.moveZeroes(nums);

    cout << "After moving zeroes:  ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
