/*1752. Check if Array is Sorted and Roated
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (nums[i] > nums[(i + 1) % len])
            {
                count++;
                if (count > 1)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};

    cout << "Original array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    bool result = sol.check(nums);

    cout << result;

    return 0;
}