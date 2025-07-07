/*1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end())
            {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
        cout << "Values: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
    }
    else
    {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}
