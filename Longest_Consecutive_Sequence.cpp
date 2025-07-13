/*128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int result = 1;
        int currEle = nums[0];
        int curRun = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == currEle)
                continue; // Skip duplicates
            if (nums[i] - 1 == currEle)
            {
                curRun++;
            }
            else
            {
                curRun = 1; // Reset current run
            }
            currEle = nums[i];
            result = max(result, curRun);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence Length: " << sol.longestConsecutive(nums) << endl;

    // Test case 2
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Longest Consecutive Sequence Length: " << sol.longestConsecutive(nums2) << endl;

    // Test case 3 (empty input)
    vector<int> nums3 = {};
    cout << "Longest Consecutive Sequence Length: " << sol.longestConsecutive(nums3) << endl;

    return 0;
}
