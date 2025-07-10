/*136. Single Number
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int op = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            op ^= nums[i];
        }
        return op;
    }
};

int main()
{
    Solution solution;

    // Example input: all numbers appear twice except 5
    vector<int> nums = {2, 3, 5, 4, 3, 2, 4};

    int result = solution.singleNumber(nums);

    cout << "The single number is: " << result << endl;

    return 0;
}
