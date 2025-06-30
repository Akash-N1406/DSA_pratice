/*2200. Find All K-Distant Indices in an Array
You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.

Return a list of all k-distant indices sorted in increasing order.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        int n = nums.size();
        vector<bool> is_k_distant(n, false);
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == key)
            {
                int start = max(0, j - k);
                int end = min((int)nums.size() - 1, j + k);
                for (int i = start; i <= end; i++)
                {
                    is_k_distant[i] = true;
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i)
        {
            if (is_k_distant[i])
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 2, 1, 2}; // Example input
    int key = 2;
    int k = 1;

    Solution sol;
    vector<int> result = sol.findKDistantIndices(nums, key, k);

    cout << "K-distant indices: ";
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
