/*169. Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int ele;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
                ele = nums[i];
            if (nums[i] == ele)
                count++;
            else
                count--;
        }
        return ele;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    // Calling majorityElement
    int result = sol.majorityElement(nums);

    // Output result
    cout << "Majority Element: " << result << endl;

    return 0;
}
