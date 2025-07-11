/*31. Next Permutation
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int index = -1;

        // Step 1: Find the pivot (first number from the end that is smaller than the next one)
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }

        // Step 2: If no pivot, reverse the entire array
        if (index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the next larger number from the end and swap with nums[index]
        for (int i = n - 1; i > index; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 4: Reverse the suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3}; // Example input

    cout << "Original permutation: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
