/*26. Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int k = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main()
{
    // Example input: sorted vector with duplicates
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution solution;
    int k = solution.removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Modified array with unique elements: ";
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}