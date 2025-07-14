/*18. 4Sum
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
        {
            return res;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicate 'i'

            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue; // Skip duplicate 'j'

                int k = j + 1;
                int l = nums.size() - 1;

                while (k < l)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1])
                            k++; // Skip duplicate 'k'
                        while (k < l && nums[l] == nums[l + 1])
                            l--; // Skip duplicate 'l'
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = sol.fourSum(nums, target);

    cout << "Quadruplets summing to " << target << ":\n";
    for (const auto &quad : result)
    {
        cout << "[";
        for (size_t i = 0; i < quad.size(); ++i)
        {
            cout << quad[i];
            if (i != quad.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
