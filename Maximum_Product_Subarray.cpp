/*152. Maximum Product Subarray
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = INT_MIN;
        int pre = 1;
        int suf = 1;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (pre == 0)
                pre = 1;
            if (suf == 0)
                suf = 1;
            pre = pre * nums[i];
            suf = suf * nums[n - i - 1];
            ans = max(ans, max(pre, suf));
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // Example test case
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray: " << sol.maxProduct(nums) << endl;

    // Additional test case
    vector<int> nums2 = {-2, 0, -1};
    cout << "Maximum product subarray: " << sol.maxProduct(nums2) << endl;

    return 0;
}
