/*560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prevSum;
        prevSum[0] = 1;
        int count = 0;
        int curr = 0;
        for (int num : nums)
        {
            curr += num;
            if (prevSum.find(curr - k) != prevSum.end())
            {
                count += prevSum[curr - k];
            }
            prevSum[curr]++;
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;

    Solution sol;
    int result = sol.subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k << " is: " << result << endl;

    return 0;
}
