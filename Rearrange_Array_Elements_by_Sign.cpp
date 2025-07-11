/*2149. Rearrange Array Elements by Sign
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);
        int posIndex = 0;
        int negIndex = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                result[posIndex] = nums[i];
                posIndex += 2;
            }
            else
            {
                result[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    Solution sol;
    vector<int> result = sol.rearrangeArray(nums);

    cout << "Rearranged array: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
