/*189. Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
    public:
        void rotate(vector<int> &nums, int k)
        {
            int len = nums.size();
            int rotate = k % len;
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + rotate);
            reverse(nums.begin() + rotate, nums.end());
        }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    cout << "Original array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    sol.rotate(nums, k);

    cout << "Rotated array by " << k << " positions: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}